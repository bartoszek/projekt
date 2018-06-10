#include	<baza_lekow.h>


int sprawdz_kategorie(baza_lekow* baza_lekow,char* kategoria) //0=kategoria istnieje 1=kategoria nie istnieje
{
	Queue_iterator iter;
	Queue_iterator_Int(iter,baza_lekow->kategorie);
	while((lhs=Queue_next(iter))!=NULL){
		if(strcmp(lhs,kategoria)==0)
		{
			return 0;
		}
	}
	return 1;
}

int dodaj_lek(baza_lekow* baza_lekow,lek lek)
{
	if(sprawdz_kategorie(baza_lekow,lek.kategoria))
	{
		Queue_push(baza_lekow->leki,(void*)&lek);
	}
	else
	{
		fprintf(stderr, "Kategoria %s nie istnieje, proszę ją najpierw dodać!\n",lek.kategoria);
	}
}

int porownaj_leki(lek* lhs,lek* rhs) //0=takie same, 1=ta sama nazwa - różne kategorie, 2=te same kategorie - różne nazwy, 3=różne nazwy i kategorie.
{
	if(strcmp(lhs->kategoria,rhs->kategoria)==0)
	{
		if(strcmp(lhs->nazwa,rhs->nazwa)==0)
			return 0;
		else
			return 2;
	}
	else if(strcmp(lhs->nazwa,rhs->nazwa)<2)
	{
		return 1
	}
	else
	{
		return 3
	}
}

int usun_lek(baza_lekow* baza, lek lek) //usuwa wszystkie leki o danej nazwie ze wszystkiech kategorii - zwraca ilość usuniętych leków.
{
	int retval=0
	Queue_iterator iter;
	Queue_iterator_Int(iter,baza_lekow->leki);
	void* lhs;
	while((lhs=Queue_next(iter)!=NULL))
	{
		if(porownaj_leki(lhs,lek)<=1)
		{
			Queue_remove(iter);
			retval++;
		}
	}
	return retval;
}

int dadaj_kategorie(baza_lekow* baza_lekow, char* kategoria)
{
	if(sprawdz_kategorie(kategoria)==1)
	{
		Queue_push(baza_lekow->kategorie,kategoria);
		return 0;
	}
	else
	{
		fprintf(stderr, "Kategoria %s już istnieje!\n",lek.kategoria);
		return 1;
	}
}

int usun_kategorie(baza_lekow* baza_lekow,char* kategoria) //usuwa kategorie i leki z nią związane - zwraca ilość usuniętych leków, lub -1 jeśli kategoria nie istnieje
{
	int retval=0;
	if(sprawdz_kategorie(baza_lekow,kategoria)==0)
	{
		Queue_iterator iter;
		Queue_iterator_Int(iter,baza_lekow->leki);
		lek kategoria={"",kategoria}; //lek bez nazwy do porównywania kategorii
		lek* tmp=NULL;
		while((lek=Queue_next(iter))!=NULL){
			if(porownaj_leki(lek,kategoria)==2) //ta sama kategoria
			{
				Queue_remove(iter);
				retval++;
			}
		}
		fprintf(stderr, "Usunięto %d leków związanych z kategorią %s\n",retval,kategoria);
		return retval;
	}
	else
	{
		fprintf(stderr, "Kategoria %s nie istnieje!\n",lek.kategoria);
		return -1;
	}
}

int wyswietl_liste_lekow(baza_lekow* baza_lekow)
{
	int index=1;
	int liczba_lekow=baza_lekow->leki->sizeOfQueue;
	printf("Baza Leków zawiera %d wpisów\n", liczba_lekow);
	Queue_iterator iter;
	Queue_iterator_Int(iter,baza_lekow->leki);
	lek *lek=NULL;
	while((lek=Queue_next(iter))!=NULL)
	{
		printf("[%2d/%2d] Nazwa Leku: %s\tKategoria Leku: %s\n",index++, liczba_lekow, lek->nazwa, lek->kategoria);
	}
}

int wyswietl_liste_kategorii(baza_lekow*)
{
	int index=1;
	int liczba_kategorii=baza_lekow->kategorie->sizeOfQueue;
	printf("Baza Leków zawiera %d kategori\n", liczba_kategorii);
	Queue_iterator iter;
	Queue_iterator_Int(iter,baza_lekow->leki);
	char *kategoria=NULL;
	while((kategoria=Queue_next(iter))!=NULL)
	{
		printf("[%2d/%2d] Nazwa Kategoria: %s\n",index++, liczba_kategorii, kategoria);
	}
}

int wczytaj_baze_lekow(baza_lekow* baza_lekow,FILE *plik,FLAG flag)
{
	if (flag==TXT)
	{
		lek *lek=malloc(sizeof(lek));
		while(fscanf(plik,"%"ROZMIAR"s\t%"ROZMIAR"%s\n",lek->nazwa,lek->kategoria)!=EOF)
		{
			if(sprawdz_kategorie(baza_lekow,lek->kategorie)==0)
			{
				dodaj_kategorie(baza_lekow,lek->kategorie);
			}
			dodaj_lek(baza_lekow,lek);			
		}
	}
	else //binary
	{
		lek *lek=malloc(sizeof(lek));
		while(fread(plik,sizeof(lek),lek)!=EOF)
		{
			if(sprawdz_kategorie(baza_lekow,lek->kategorie)==0)
			{
				dodaj_kategorie(baza_lekow,lek->kategorie);
			}
			dodaj_lek(baza_lekow,lek);
		}
		
	}
}

int zapisz_baze_lekow(baza_lekow* baza_lekow,FILE* file,FLAG falg)
{
	Queue_iterator iter;
	Queue_iterator_Int(iter,baza_lekow);
	lek *lek=NULL;
	if (flag==TXT)
	{
		while((lek=Queue_next(iter)!=NULL))
		{
			fprintf(plik,"%"ROZMIAR"s\t%"ROZMIAR"%s\n",lek->nazwa,lek->kategoria);
		}
	}
	else //binary
	{
		while((lek=Queue_next(iter)!=NULL))
		{
			fwrite(plik,sizeof(lek),lek);
		}
	}
}

int zwolnij_baze_lekow(baza_lekow* baza_lekow)
{
	Queue_remove(baza_lekow->kategorie);
	Queue_remove(baza_lekow->leki);
	free(baza_lekow);
	baza_lekow=NULL;
}

int zainicjuj_baze_lekow(baza_lekow* baza_lekow)
{
	baza_lekow=malloc(sizeof(baza_lekow))
	baza_lekow->kategorie=malloc(sizeof(Queue));
	baza_lekow->leki=malloc(sizeof(Queue));
	Queue_Int(baza_lekow->kategorie,sizeof(char[ROZMIAR]));
	Queue_Int(baza_lekow->leki,sizeof(lek));
}
