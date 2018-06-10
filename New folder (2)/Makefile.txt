CC=gcc
prefix=bin


.PHONY: all

all: baza_lekow

baza_lekow: kolejka.o baza_danych.o
	$(CC) kolejka.o baza_danych.o -o baza_lekow

kolejka.o:
	$(CC) kolejka.c -c -o kolejka.o

baza_danych.o:
	$(CC) baza_danych.c -c -o baza_danych.o

clean:
	rm -f *o baza_lekow

install: baza_lekow
	install -m 0755 baza_lekow $(prefix)/baza_lekow
	install -m 0644 kategorie $(prefix)/kategorie