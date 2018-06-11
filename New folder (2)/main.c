#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza_lekow.h"


int main()
{

    baza_lekow *baza_lekow=malloc(sizeof(baza_lekow));
    zainicjuj_baze_lekow(baza_lekow);

    int opcja=0;
    lek lek;
    char kategoria[ROZMIAR];
    char path[256];
    FLAG flag;
    FILE* file=NULL;
                
    printf("---------- Baza lekow ----------\n");

    while(1)
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
            case 1: ;
                printf("Nazwa leku: ");
                scanf("%"ROZMIAR_str"s",lek.nazwa);
                printf("Kategoria leku: ");
                scanf("%"ROZMIAR_str"s",lek.kategoria);
                dodaj_lek(baza_lekow,lek);
                break;

            case 2: ;
                printf("Nazwa leku: ");
                scanf("%"ROZMIAR_str"s",lek.nazwa);
                printf("Kategoria leku: ");
                scanf("%"ROZMIAR_str"s",lek.kategoria);
                usun_lek(baza_lekow,lek);
                break;

            case 3: ;
                printf("Kategoria: ");
                scanf("%"ROZMIAR_str"s",kategoria);
                dodaj_kategorie(baza_lekow,kategoria);
		wyswietl_liste_kategorii(baza_lekow);
                break;

            case 4:
                printf("Kategoria: ");
                scanf("%"ROZMIAR_str"s",kategoria);
                usun_kategorie(baza_lekow,kategoria);
		wyswietl_liste_kategorii(baza_lekow);
                break;

            case 5:
                wyswietl_liste_lekow(baza_lekow);
                break;

            case 6:
                printf("Ścieżka do pliku: ");
                scanf("%257s",path);
                printf("Typ pliku [1=textowy,2=binarny]");
                scanf("%d", &flag);
                if(flag==TXT)
                {
                    file=fopen(path,"rt");
                }
                else
                {
                    file=fopen(path,"rb");
                }
                if(file)
                {
                    wczytaj_baze_lekow(baza_lekow,file,flag);
                }
                else
                {
                    fprintf(stderr, "Error opening file %s\n",path );
                }
		fclose(file);
                break;

            case 7:
                printf("Ścieżka do pliku: ");
                scanf("%257s",path);
                printf("Typ pliku [1=textowy,2=binarny]");
                scanf("%d", &flag);
                if(flag==TXT)
                    file=fopen(path,"wt");
                else
                    file=fopen(path,"wb");
                if(file)
                {
                    zapisz_baze_lekow(baza_lekow,file,flag);    
                }
                else
                {
                    fprintf(stderr, "Error opening file %s\n",path );
                }
		fclose(file);
                break;

            case 0:
                zwolnij_baze_lekow(baza_lekow);
                return 0;
        }

    }
   
    return 0;
}
