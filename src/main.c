#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <gelf.h>
#include <getopt.h>
#include <libelf.h>
#include <stdlib.h>
#include "libs/machine_arch.h"


/* Global Variables */
int archvalue;
int e_entryvalue;
char * e_machine;
int phdrsize;
int sizehdr;
size_t shdrtablecount;

/* Function Prototypes */
int parser(char* fvalue,int runstate);
void usage(FILE* stream);


int main(int argc, char **argv) {

    int fflag = 0;
    int aflag = 0;
    int hflag = 0;
    int sflag = 0;
    int dflag = 0;

    char *fvalue = NULL;

    while (1) {
        static struct option long_options[] = {
            {"all", no_argument, 0, 'a'},
            {"file", required_argument, 0, 'f'},
            {"section-headers", no_argument, 0, 'S'},
            {"file-headers", no_argument, 0, 'h'},
            {0, 0, 0, 0}
        };

        int option_index = 0;
        int c = getopt_long(argc, argv, "aShf:", long_options, &option_index);
        if (c == -1) break;

        switch (c) {
            case 'a':
                aflag = 1;
                break;
            case 'f':
                fflag = 1;
                fvalue = optarg;
                break;
            case 'S':
                sflag = 1;
                break;
            case 'h':
                hflag = 1;
                break;
            default:
                usage(stdout);
                break;
        }
    }

    if (((fflag && aflag) == 1) && ((sflag || hflag) == 0)) parser(fvalue,0);
    else if (((fflag && hflag) == 1) && ((aflag || sflag) == 0)) parser(fvalue,1);
    else if (((fflag && sflag) == 1) && ((aflag || hflag) == 0)) parser(fvalue,2);
    else usage(stderr);

}

int parser(char* fvalue,int runstate){

    int FD;
    Elf *codeELF;
    Elf64_Ehdr *ehdr64;
    Elf32_Ehdr *ehdr32;
    Elf64_Half archstate;
    FD = open(fvalue,O_RDONLY);

    if (elf_version(EV_CURRENT) == EV_NONE) {
        fprintf(stderr, "Problem in ELF version setting: %s\n", elf_errmsg(-1));
        return -1;
    }

    if ((codeELF = elf_begin(FD, ELF_C_RDWR, NULL)) == NULL) {
        fprintf(stderr, "ELF_BEGIN for the ELF file : %s\n", elf_errmsg(-1));
        return -1;
    }

    if (elf_kind(codeELF) != ELF_K_ELF) {
        fprintf(stderr, "The file isn't ELF.\n");
        return -1;
    }

    archstate = gelf_getclass(codeELF);

    switch (archstate) {

        case ELFCLASS64:
            archvalue = 64;
            break;
        case ELFCLASS32:
            archvalue = 32;
            break;
        default:
            fprintf(stderr, "Unknown architecture.\n");
            return -1;
    }
    if (runstate == 0 || runstate == 1 || runstate == 2) {

        if (runstate == 0 || runstate == 1) {

            if (archstate == ELFCLASS64) {

                ehdr64 = elf64_getehdr(codeELF);
                e_entryvalue = ehdr64->e_entry;
                e_machine = get_machine_name(ehdr64->e_machine);
                phdrsize = ehdr64->e_phentsize;
            }else {

                ehdr32 = elf32_getehdr(codeELF);
                e_entryvalue = ehdr32->e_entry;
                e_machine = get_machine_name(ehdr32->e_machine);
                phdrsize = ehdr32->e_phentsize;
            }

            if (elf_getshdrnum(codeELF, &shdrtablecount) != 0) {
                fprintf(stderr, "Failed to get section headers count: %s\n", elf_errmsg(-1));
                return -1;
            }

            printf("Entry Point:\t\t\t 0x%x\n",e_entryvalue);
            printf("CLASS:\t\t\t\t ELF%d\n",archvalue);
            printf("Machine:\t\t\t %s\n",e_machine);
            printf("Size of program headers:\t %d\n",phdrsize);
            printf("Number of section headers:\t %d\n",shdrtablecount);


        }

        if (runstate == 0 || runstate == 2) {
            Elf_Scn *scn=NULL;
            GElf_Shdr shdr;
            size_t n, shstrndx, sz;
            int offset;
            char *name;

            if (elf_getshdrstrndx(codeELF, &shstrndx) != 0)
                    fprintf(stderr, "elf_getshdrstrndx() failed : %s\n", elf_errmsg(-1));
            while ((scn = elf_nextscn(codeELF, scn)) != NULL) {
                    gelf_getshdr(scn, &shdr);

                    name = elf_strptr(codeELF, shstrndx, shdr.sh_name);
                    printf("%-4.4jd %-18s\t\t0x%-22x\n", (uintmax_t) elf_ndxscn(scn), name, shdr.sh_offset);
            }
        }
    }
}

void usage(FILE* stream){
    fprintf(stream, ("Usage: elfparser <options>\n"));
    fprintf(stream, (" Display information about the contents of ELF format files\n"));
    fprintf(stream, (" Options are:\n"));
    fprintf(stream, ("  -a --all                  Equivalent to: -h -S \n"));
    fprintf(stream, ("  -h --file-headers         Display the ELF file header\n"));
    fprintf(stream, ("  -S --section-headers      Display the sections header\n"));
    fprintf(stream, ("  -f --file                 Load file for parsing\n"));

    exit(1);
}