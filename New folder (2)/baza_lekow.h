#include <kolejka.h>

#define ROZMIAR 20;
typedef enum {TXT=1,BIN=2} FLAG;

typedef struct _lek
{
	char kategoria[ROZMIAR];
	char nazwa[ROZMIAR];
}lek;

typedef struct _baza_lekow
{	
	Queue *kategorie;
	Queue *leki;
}baza_lekow;


int dodaj_lek(baza_lekow*,lek);

int usun_lek(baza_lekow*, lek);

int dadaj_kategorie(baza_lekow*, char*);

int usun_kategorie(baza_lekow*, char*);

int wyswietl_liste_lekow(baza_lekow*);

int wyswietl_liste_kategorii(baza_lekow*);

int wczytaj_baze_lekow(baza_lekow*,FILE,FLAG);

int zapisz_baze_lekow(baza_lekow*,FILE,FLAG);

int zwolnij_baze_lekow(baza_lekow*);

int zainicjuj_baze_lekow(baza_lekow*);