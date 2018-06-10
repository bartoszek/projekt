CC=gcc
CFLAGS=-I.
prefix=bin


.PHONY: all

all: baza_lekow

main: kolejka.o baza_lekow.o kolejka.h baza_lekow.h	
	$(CC) kolejka.o baza_danych.o -o baza_lekow

kolejka.o: kolejka.c kolejka.h
	$(CC) -c kolejka.c kolejka.h $(CFLAGS)

baza_danych.o: baza_lekow.c baza_lekow.h kolejka.h
	$(CC) -c baza_lekow.c baza_lekow.h kolejka.h $(CFLAGS)

clean:
	rm -f *o baza_lekow

install: baza_lekow
	install -m 0755 baza_lekow $(prefix)/baza_lekow
	install -m 0644 kategorie $(prefix)/kategorie