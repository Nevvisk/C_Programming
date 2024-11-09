CC = gcc
OUTPUTFLAG = -o 
COMPFLAG = -c

all: main clearbutmain
	
main: main.o
	@gcc main.o $(OUTPUTFLAG) main
	@chmod +x main

main.o: main.c 
	@$(CC) $(COMPFLAG) main.c 

clear: 
	@rm -f main main.o

clearbutmain:
	@rm -f main.o
