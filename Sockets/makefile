CC = gcc
CCFLAG = -Wimplicit-function-declaration

all: main

main: main.o
	@$(CC) main.o $(CCFLAG) -o main
	@chmod +x main

main.o: main.c
	@$(CC) -c $(CCFLAG) main.c

clear:
	@rm -f main main.o
