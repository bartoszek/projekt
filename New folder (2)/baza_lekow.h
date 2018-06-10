#include <kolejka.h>

#define ROZMIAR 20
typedef enum {TXT,BIN} FLAG;

typedef struct _lek
{
	char rodzaj[ROZMIAR];
	char nazwa[ROZMIAR];
}lek;

typedef struct _baza_lekow
{	
	Queue kategorie;
	Queue leki;
}baza_lekow;

dodaj_lek(baza_lekow,lek);

usun_lek(baza_lekow, lek);

dadaj_kategorie(baza_lekow, kategoria);

usun_kategorie(baza_lekow, kategoria);

wyswietl_liste_lekow(baza_lekow);

wyswietl_liste_kategorii(baza_lekow);

wczytaj_liste(baza_lekow,FILE,FLAG);

zapisz_liste(baza_lekow,FILE,FLAG);

zwolnij(baza_lekow);