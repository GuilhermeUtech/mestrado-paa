SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -O3
NOME=rgen
ENTRADA=entry.txt
MAIN=main

default: build

clean:
	rm -f $(MAIN) $(NOME) *.o core a.out *.*~ Makefile~

$(NOME).o: $(NOME).c $(NOME)_publico.h $(NOME)_privado.h
	$(CC) $(CFLAGS) -c $(NOME).c -o $(NOME).o

build: $(MAIN).c $(MAIN).h $(NOME).o
	$(CC) $(CFLAGS) $(MAIN).c $(NOME).o -o $(MAIN)

valgrind:
	cat $(ENTRADA) | valgrind ./$(MAIN)

all: build