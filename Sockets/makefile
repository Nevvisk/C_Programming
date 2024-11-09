CC = gcc
CCFLAG = -Wimplicit-function-declaration

all: main clearwithoutmain

main: main.o
	@$(CC) main.o $(CCFLAG) -o main
	@chmod +x main

main.o: main.c
	@$(CC) -c $(CCFLAG) main.c

clear:
	@rm -f main main.o

clearwithoutmain:
	@rm -f main.o
