#define ROZMIAR 20
typedef enum {TXT,BIN} FLAG;

typedef struct Lek
{
	char rodzaj[ROZMIAR];
	char nazwa[ROZMIAR];
}Lek_t;

dodaj_pozycje(baza_lekow);

usun_pozyzje(baza_lekow);

wyswietl_liste_pozycji(baza_lekow);

wczytaj_liste(baza_lekow,plik,FLAG);

zapisz_liste(baza_lekow,plik,FLAG);

zwolnij(baza_lekow);