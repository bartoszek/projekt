#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"

#define PLIK_TXT "plik.txt"
#define PLIK_BIN "plik.bin"

#define ROZMIAR 20

typedef struct Lek
    {
    char rodzaj[ROZMIAR];
    char nazwa[ROZMIAR];
    struct node * next;
}Lek_t;

dodaj_nowa_pozyjce();

dodaj_nowa_pozyjce();

wyswietl_liste_pozycji();

wczytaj_liste_z_pliku();

zapisz_liste_do_pliku();

zwolnij();

int main()
{
    printf("---------- Baza lekow ----------\n");
int opcja, koniec=0;

    while(!koniec)
    {
        printf("[1] dodaj nową pozycje\n");
        printf("[2] usun pozycje\n");
        printf("[3] wyswietl liste pozycji\n");
        printf("[4] wczytaj liste z pliku\n");
        printf("[5] zapis listę do pliku\n");
        printf("[0] Zakonczenie programu\n");

        printf("Wybierz opcje: ");
        scanf("%d", &opcja);

        switch(opcja)
        {
            case 1:
                dodaj_nowa_pozyjce();

            case 2:
               dodaj_nowa_pozyjce();
            

                break;

            case 3:
                wyswietl_liste_pozycji();
                break;

            case 4:
                wczytaj_liste_z_pliku();
                break;

            case 5:
                zapisz_liste_do_pliku();
                break;

            case 0:
            default:
                koniec=1;
                break;
        }

    }

    zwolnij();
   
    return 0;
}