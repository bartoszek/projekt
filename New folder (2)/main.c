#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza_lekow.h"

#define PLIK_TXT "baza_lekow.txt"
#define PLIK_BIN "baza_lekow.bin"


int main()
{

    baza_lekow *baza_lekow;
    int zainicjuj_baze_lekow(baza_lekow);

    int opcja=0;
    printf("---------- Baza lekow ----------\n");

    while()
    {
        printf("[1] dodaj lek\n");
        printf("[2] usuń lek\n");
        printf("[3] dodaj kategorię\n");
        printf("[4] usuń kategorię\n");
        printf("[5] wyswietl listę leków\n");
        printf("[6] wczytaj listę leków z pliku\n");
        printf("[7] zapis listę leków do pliku\n");
        printf("[0] Zakończenie programu\n");

        printf("Wybierz opcje: ");
        scanf("%d", &opcja);

        switch(opcja)
        {
            case 1:
                lek lek;
                printf("Nazwa leku: ");
                scanf("%"ROZMIAR"s",lek->nazwa);
                printf("Kategoria leku: ");
                scanf("%"ROZMIAR"s",lek->kategoria)
                dodaj_lek(baza_lekow,&lek);
                break;

            case 2:
                lek lek;
                printf("Nazwa leku: ");
                scanf("%"ROZMIAR"s",lek->nazwa);
                printf("Kategoria leku: ");
                scanf("%"ROZMIAR"s",lek->kategoria)
                usuń_lek(baza_lekow,&lek);
                break;

            case 3:
                char kategoria[ROZMIAR]
                printf("Kategoria: ");
                scanf("%"ROZMIAR"s",kategoria)
                dodaj_kategorie(baza_lekow,kategoria);
                break;

            case 4:
                char kategoria[ROZMIAR]
                printf("Kategoria: ");
                scanf("%"ROZMIAR"s",kategoria)
                usun_kategorie(baza_lekow,kategoria);
                break;

            case 5:
                wyswietl_liste_lekow(baza_lekow);
                break;

            case 6:
                char path[256];
                FLAG falg;
                printf("Ścieżka do pliku: ");
                scanf("%257s",path);
                printf("Typ pliku [1=binarny,2=textowy]")
                scanf("%d", &flag)
                if(flag==TXT)
                    FILE* file=fopen(path,"r");
                else
                    FILE* file=fopen(path,"br");
                wczytaj_baze_lekow(baza_lekow,file,flag);
                break;

            case 7:
                char path[256];
                FLAG falg;
                printf("Ścieżka do pliku: ");
                scanf("%257s",path);
                printf("Typ pliku [1=binarny,2=textowy]")
                scanf("%d", &flag)
                if(flag==TXT)
                    FILE* file=fopen(path,"r");
                else
                    FILE* file=fopen(path,"br");
                zapisz_baze_lekow(baza_lekow,file,flag);
                break;

            case 0:
                zwolnij_baze_lekow(baza_lekow);
                return 0;
        }

    }
   
    return 0;
}