#include	<baza_lekow.h>

dodaj_nowa_pozyjce(baza_lekow)
{
	Lek *nowa = NULL, *tmp, *pom;
 	Lek.rodzaj = bufor1, Lek.nazwa = bufor2

	while (*head != NULL)
	{
		tmp = (Lek*)malloc(sizeof(Lek));
		tmp->dane.rodzaj = (char*)malloc(sizeof(char) * strlen((*head)->dane.rodzaj) + 1);
		strcpy(tmp->dane.rodzaj, (*head)->dane.rodzaj);
		tmp->dane.nazwa = (char*)malloc(sizeof(char) * strlen((*head)->dane.nazwa) + 1);
		strcpy(tmp->dane.nazwa, (*head)->dane.nazwa);
		tmp->next = NULL;
		if (nowa == NULL)
			nowa = tmp;
		else if (strcmp(nowa->dane.rodzaj, tmp->dane.rodzaj) > 0)
		{
			tmp->next = nowa;
			nowa = tmp;
		}
		else
		{
			pom = nowa;
			while (pom->next != NULL && strcmp(pom->next->dane.rodzaj, tmp->dane.rodzaj) < 0)
				pom = pom->next;
			tmp->next = pom->next;
			pom->next = tmp;
		}
		pom = *head;
		*head = (*head)->next;
		if (pom->dane.rodzaj)
			free(pom->dane.rodzaj);
		if (pom->dane.nazwa)
			free(pom->dane.nazwa);
		free(pom);
	}
	*head = nowa;
		return 0;
}


wyswietlanie_listy_pozycji(Lek *head)
{
	Lek *tmp;
 
	tmp = head;
	if (tmp == NULL)
		printf("Brak elementow");
	else
	{
		while (tmp != NULL)
		{
			printf("%s %s\n", tmp->dane.rodzaj, tmp->dane.nazwa);
			tmp = tmp->next;
		}
	}
	return 0;
}  

void odczyt_z_pliku(Lek **head)
{
	FILE *wczytaj = NULL;
	char nazwa_pliku[] = "lista_Lekow.txt";
	char bufor[100 + 1];
	Lek *tmp, *pom;
 
	wczytaj = fopen(nazwa_pliku, "r");
	if (wczytaj == NULL)
		printf("Blad otwarcia pliku");
	else
	{
		while (fscanf(wczytaj, "%s", bufor) != EOF)
		{
			tmp = (Lek*)malloc(sizeof(Lek));
			tmp->next = NULL;
			tmp->dane.rodzaj = (char*)malloc(sizeof(char)* (strlen(bufor) + 1));
			strcpy(tmp->dane.rodzaj, bufor);
			fscanf(wczytaj, "%s", bufor);
			tmp->dane.nazwa = (char*)malloc(sizeof(char)* (strlen(bufor) + 1));
			strcpy(tmp->dane.nazwa, bufor);
 
			if (*head == NULL)
				*head = tmp;
			else
			{
				pom = *head;
				while (pom->next != NULL)
					pom = pom->next;
				pom->next = tmp;
			}
		}
		printf("Plik zostal wczytany");
	}
	fclose(wczytaj);
}

zapisz_do_pliku(Lek *head)
{
	FILE *zapisz = NULL;
	Lek *tmp;
	char nazwa_pliku[] = "lista_pozycji.txt";
 
	if (head == NULL)
		printf("Nie ma elementow do zapisania");
	else
	{
		zapisz = fopen(nazwa_pliku, "w");
		if (zapisz == NULL)
			printf("Blad otwarcia pliku");
		else
		{
			tmp = head;
			while (tmp != NULL)
			{
				fprintf(zapisz, "%s\n", tmp->dane.rodzaj);
				fprintf(zapisz, "%s\n", tmp->dane.nazwa);
				tmp = tmp->next;
			}
			printf("Lista zostala zapisana");
		}
		fclose(zapisz);
	}
}
