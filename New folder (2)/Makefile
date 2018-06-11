CC=gcc
CFLAGS=-I.
prefix=bin

debug: CFLAGS+= -g3 -gdwarf
debug: all

.PHONY: all

all: main

main: main.c kolejka.o baza_lekow.o kolejka.h baza_lekow.h	
	$(CC) main.c baza_lekow.o kolejka.o baza_lekow.h kolejka.h -o baza_lekow $(CFLAGS)

kolejka.o: kolejka.c kolejka.h
	$(CC) -c kolejka.c kolejka.h $(CFLAGS)

baza_lekow.o: baza_lekow.c baza_lekow.h kolejka.h
	$(CC) -c baza_lekow.c baza_lekow.h kolejka.h $(CFLAGS)

clean:
	rm -f *o baza_lekow

install: main
	install -m 0755 -d $(prefix)
	install -m 0755 baza_lekow $(prefix)/baza_lekow
