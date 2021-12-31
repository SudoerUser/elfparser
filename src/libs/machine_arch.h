static char* get_machine_name (unsigned e_machine) {
  static char buff[64]; /* XXX */

  switch (e_machine) {
      /* Please keep this switch table sorted by increasing EM_ value.  */
      /* 0 */
    case EM_NONE:		return ("None");
    case EM_M32:		return "WE32100";
    case EM_SPARC:		return "Sparc";
    case EM_386:		return "Intel 80386";
    case EM_68K:		return "MC68000";
    case EM_88K:		return "MC88000";
    case EM_IAMCU:		return "Intel MCU";
    case EM_860:		return "Intel 80860";
    case EM_MIPS:		return "MIPS R3000";
    case EM_S370:		return "IBM System/370";
      /* 10 */
    case EM_MIPS_RS3_LE:	return "MIPS R4000 big-endian";
    case EM_PARISC:		return "HPPA";
    case EM_SPARC32PLUS:	return "Sparc v8+" ;
    case EM_960:		return "Intel 80960";
    case EM_PPC:		return "PowerPC";
      /* 20 */
    case EM_PPC64:		return "PowerPC64";
    case EM_S390:		return "IBM S/390";
    case EM_SPU:		return "SPU";
      /* 30 */
    case EM_V800:		return "Renesas V850 (using RH850 ABI)";
    case EM_FR20:		return "Fujitsu FR20";
    case EM_RH32:		return "TRW RH32";
      /* 40 */
    case EM_ARM:		return "ARM";
    case EM_SH:			return "Renesas / SuperH SH";
    case EM_SPARCV9:		return "Sparc v9";
    case EM_TRICORE:		return "Siemens Tricore";
    case EM_ARC:		return "ARC";
    case EM_H8_300:		return "Renesas H8/300";
    case EM_H8_300H:		return "Renesas H8/300H";
    case EM_H8S:		return "Renesas H8S";
    case EM_H8_500:		return "Renesas H8/500";
      /* 50 */
    case EM_IA_64:		return "Intel IA-64";
    case EM_MIPS_X:		return "Stanford MIPS-X";
    case EM_COLDFIRE:		return "Motorola Coldfire";
    case EM_68HC12:		return "Motorola MC68HC12 Microcontroller";
    case EM_MMA:		return "Fujitsu Multimedia Accelerator";
    case EM_PCP:		return "Siemens PCP";
    case EM_NCPU:		return "Sony nCPU embedded RISC processor";
    case EM_NDR1:		return "Denso NDR1 microprocesspr";
    case EM_STARCORE:		return "Motorola Star*Core processor";
    case EM_ME16:		return "Toyota ME16 processor";
      /* 60 */
    case EM_ST100:		return "STMicroelectronics ST100 processor";
    case EM_TINYJ:		return "Advanced Logic Corp. TinyJ embedded processor";
    case EM_X86_64:		return "Advanced Micro Devices X86-64";
    case EM_PDSP:		return "Sony DSP processor";
    case EM_PDP10:		return "Digital Equipment Corp. PDP-10";
    case EM_PDP11:		return "Digital Equipment Corp. PDP-11";
    case EM_FX66:		return "Siemens FX66 microcontroller";
    case EM_ST9PLUS:		return "STMicroelectronics ST9+ 8/16 bit microcontroller";
    case EM_ST7:		return "STMicroelectronics ST7 8-bit microcontroller";
    case EM_68HC16:		return "Motorola MC68HC16 Microcontroller";
      /* 70 */
    case EM_68HC11:		return "Motorola MC68HC11 Microcontroller";
    case EM_68HC08:		return "Motorola MC68HC08 Microcontroller";
    case EM_68HC05:		return "Motorola MC68HC05 Microcontroller";
    case EM_SVX:		return "Silicon Graphics SVx";
    case EM_ST19:		return "STMicroelectronics ST19 8-bit microcontroller";
    case EM_VAX:		return "Digital VAX";
    case EM_CRIS:		return "Axis Communications 32-bit embedded processor";
    case EM_JAVELIN:		return "Infineon Technologies 32-bit embedded cpu";
    case EM_FIREPATH:		return "Element 14 64-bit DSP processor";
    case EM_ZSP:		return "LSI Logic's 16-bit DSP processor";
      /* 80 */
    case EM_MMIX:		return "Donald Knuth's educational 64-bit processor";
    case EM_HUANY:		return "Harvard Universitys's machine-independent object format";
    case EM_PRISM:		return "Vitesse Prism";
    case EM_AVR:		return "Atmel AVR 8-bit microcontroller";
    case EM_FR30:		return "Fujitsu FR30";
    case EM_D10V:		return "d10v";
    case EM_D30V:		return "d30v";
    case EM_V850:		return "Renesas V850";
    case EM_M32R:		return "Renesas M32R (formerly Mitsubishi M32r)";
    case EM_MN10300:		return "mn10300";
      /* 90 */
    case EM_MN10200:		return "mn10200";
    case EM_PJ:			return "picoJava";
    case EM_ARC_COMPACT:	return "ARCompact";
    case EM_XTENSA:		return "Tensilica Xtensa Processor";
    case EM_VIDEOCORE:		return "Alphamosaic VideoCore processor";
    case EM_TMM_GPP:		return "Thompson Multimedia General Purpose Processor";
    case EM_NS32K:		return "National Semiconductor 32000 series";
    case EM_TPC:		return "Tenor Network TPC processor";
    case EM_SNP1K:	        return "Trebia SNP 1000 processor";
      /* 100 */
    case EM_ST200:		return "STMicroelectronics ST200 microcontroller";
    case EM_IP2K:		return "Ubicom IP2xxx 8-bit microcontrollers";
    case EM_MAX:		return "MAX Processor";
    case EM_CR:			return "National Semiconductor CompactRISC";
    case EM_F2MC16:		return "Fujitsu F2MC16";
    case EM_MSP430:		return "Texas Instruments msp430 microcontroller";
    case EM_BLACKFIN:		return "Analog Devices Blackfin";
    case EM_SE_C33:		return "S1C33 Family of Seiko Epson processors";
    case EM_SEP:		return "Sharp embedded microprocessor";
    case EM_ARCA:		return "Arca RISC microprocessor";
      /* 110 */
    case EM_UNICORE:		return "Unicore";
    case EM_EXCESS:		return "eXcess 16/32/64-bit configurable embedded CPU";
    case EM_DXP:		return "Icera Semiconductor Inc. Deep Execution Processor";
    case EM_ALTERA_NIOS2:	return "Altera Nios II";
    case EM_CRX:		return "National Semiconductor CRX microprocessor";
    case EM_XGATE:		return "Motorola XGATE embedded processor";
    case EM_C166:
    case EM_M16C:		return "Renesas M16C series microprocessors";
    case EM_DSPIC30F:		return "Microchip Technology dsPIC30F Digital Signal Controller";
    case EM_CE:			return "Freescale Communication Engine RISC core";
      /* 120 */
    case EM_M32C:	        return "Renesas M32c";
      /* 130 */
    case EM_TSK3000:		return "Altium TSK3000 core";
    case EM_RS08:		return "Freescale RS08 embedded processor";
    case EM_ECOG2:		return "Cyan Technology eCOG2 microprocessor";
    case EM_DSP24:		return "New Japan Radio (NJR) 24-bit DSP Processor";
    case EM_VIDEOCORE3:		return "Broadcom VideoCore III processor";
    case EM_LATTICEMICO32:	return "Lattice Mico32";
    case EM_SE_C17:		return "Seiko Epson C17 family";
      /* 140 */
    case EM_TI_C6000:		return "Texas Instruments TMS320C6000 DSP family";
    case EM_TI_C2000:		return "Texas Instruments TMS320C2000 DSP family";
    case EM_TI_C5500:		return "Texas Instruments TMS320C55x DSP family";
    case EM_TI_PRU:		return "TI PRU I/O processor";
      /* 160 */
    case EM_MMDSP_PLUS:		return "STMicroelectronics 64bit VLIW Data Signal Processor";
    case EM_CYPRESS_M8C:	return "Cypress M8C microprocessor";
    case EM_R32C:		return "Renesas R32C series microprocessors";
    case EM_TRIMEDIA:		return "NXP Semiconductors TriMedia architecture family";
    case EM_QDSP6:		return "QUALCOMM DSP6 Processor";
    case EM_8051:		return "Intel 8051 and variants";
    case EM_STXP7X:		return "STMicroelectronics STxP7x family";
    case EM_NDS32:		return "Andes Technology compact code size embedded RISC processor family";
    case EM_ECOG1X:		return "Cyan Technology eCOG1X family";
    case EM_MAXQ30:		return "Dallas Semiconductor MAXQ30 Core microcontrollers";
      /* 170 */
    case EM_XIMO16:		return "New Japan Radio (NJR) 16-bit DSP Processor";
    case EM_MANIK:		return "M2000 Reconfigurable RISC Microprocessor";
    case EM_CRAYNV2:		return "Cray Inc. NV2 vector architecture";
    case EM_RX:			return "Renesas RX";
    case EM_METAG:		return "Imagination Technologies Meta processor architecture";
    case EM_MCST_ELBRUS:	return "MCST Elbrus general purpose hardware architecture";
    case EM_ECOG16:		return "Cyan Technology eCOG16 family";
    case EM_CR16:
    case EM_MICROBLAZE:
    case EM_ETPU:		return "Freescale Extended Time Processing Unit";
    case EM_SLE9X:		return "Infineon Technologies SLE9X core";
      /* 180 */
    case EM_AARCH64:		return "AArch64";
    case EM_AVR32:		return "Atmel Corporation 32-bit microprocessor";
    case EM_STM8:		return "STMicroeletronics STM8 8-bit microcontroller";
    case EM_TILE64:		return "Tilera TILE64 multicore architecture family";
    case EM_TILEPRO:		return "Tilera TILEPro multicore architecture family";
      /* 190 */
    case EM_CUDA:		return "NVIDIA CUDA architecture";
    case EM_TILEGX:		return "Tilera TILE-Gx multicore architecture family";
    case EM_CLOUDSHIELD:	return "CloudShield architecture family";
    case EM_COREA_1ST:		return "KIPO-KAIST Core-A 1st generation processor family";
    case EM_COREA_2ND:		return "KIPO-KAIST Core-A 2nd generation processor family";
    case EM_OPEN8:		return "Open8 8-bit RISC soft processor core";
    case EM_RL78:		return "Renesas RL78";
    case EM_VIDEOCORE5:		return "Broadcom VideoCore V processor";
      /* 200 */
    case EM_56800EX:		return "Freescale 56800EX Digital Signal Controller (DSC)";
    case EM_BA1:		return "Beyond BA1 CPU architecture";
    case EM_BA2:		return "Beyond BA2 CPU architecture";
    case EM_XCORE:		return "XMOS xCORE processor family";
    case EM_MCHP_PIC:		return "Microchip 8-bit PIC(r) family";
      /* 210 */
    case EM_KM32:		return "KM211 KM32 32-bit processor";
    case EM_KMX32:		return "KM211 KMX32 32-bit processor";
    case EM_KVARC:		return "KM211 KVARC processor";
    case EM_CDP:		return "Paneve CDP architecture family";
    case EM_COGE:		return "Cognitive Smart Memory Processor";
    case EM_COOL:		return "Bluechip Systems CoolEngine";
    case EM_NORC:		return "Nanoradio Optimized RISC";
    case EM_CSR_KALIMBA:	return "CSR Kalimba architecture family";
      /* 220 */
    case EM_Z80:		return "Zilog Z80";
    case EM_VISIUM:		return "CDS VISIUMcore processor";
    case EM_FT32:               return "FTDI Chip FT32";
    case EM_MOXIE:              return "Moxie";
    case EM_AMDGPU: 	 	return "AMD GPU";
      /* 230 (all reserved) */
      /* 240 */
    case EM_RISCV: 	 	return "RISC-V";
    case EM_BPF:		return "Linux BPF";
    case EM_CSKY:		return "C-SKY";

    default:
      snprintf (buff, sizeof (buff), ("<unknown>: 0x%x"), e_machine);
      return buff;
    }
}