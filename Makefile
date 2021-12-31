install:
	@gcc ./src/main.c -o ./elfparser -lelf
	@echo Compiled
clean:
	@rm -rf ./elfparser



