#include <baza_lekow.h>
#include <string.h>


int sprawdz_kategorie(baza_lekow* baza_lekow,char* kategoria) //0=kategoria istnieje 1=kategoria nie istnieje
{
	Queue_iterator iter;
	Queue_iterator_Init(&iter,baza_lekow->kategorie);
	char* lhs=NULL;
	while((lhs=(char*)Queue_next(&iter))!=NULL){
		if(strcmp(lhs,kategoria)==0)
		{
			return 0;
		}
	}
	return 1;
}

int dodaj_lek(baza_lekow* baza_lekow,lek lek)
{
	if(sprawdz_kategorie(baza_lekow,lek.kategoria)==0)
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
		return 1;
	}
	else
	{
		return 3;
	}
}

int usun_lek(baza_lekow* baza_lekow, lek rhs) //usuwa wszystkie leki o danej nazwie ze wszystkiech kategorii - zwraca ilość usuniętych leków.
{
	int retval=0;
	Queue_iterator iter;
	Queue_iterator_Init(&iter,baza_lekow->leki);
	lek *lhs=NULL;
	while((lhs=Queue_next(&iter))!=NULL)
	{
		if(porownaj_leki(lhs,&rhs)<=1)
		{
			Queue_remove(&iter);
			retval++;
		}
	}
	return retval;
}

int dodaj_kategorie(baza_lekow* baza_lekow, char* kategoria)
{
	if(sprawdz_kategorie(baza_lekow,kategoria)==1)
	{
		Queue_push(baza_lekow->kategorie,kategoria);
		return 0;
	}
	else
	{
		fprintf(stderr, "Kategoria %s już istnieje!\n",kategoria);
		return 1;
	}
}

int usun_kategorie(baza_lekow* baza_lekow,char* kategoria) //usuwa kategorie i leki z nią związane - zwraca ilość usuniętych leków, lub -1 jeśli kategoria nie istnieje
{
	int retval=0;
	if(sprawdz_kategorie(baza_lekow,kategoria)==0)
	{
		Queue_iterator iter;
		Queue_iterator_Init(&iter,baza_lekow->leki);
		lek rhs={"",""}; //lek bez nazwy do porównywania kategorii
		strcpy(rhs.kategoria,kategoria);
		lek* lek=NULL;
		while((lek=Queue_next(&iter))!=NULL){
			if(porownaj_leki(lek,&rhs)==2) //ta sama kategoria
			{
				Queue_remove(&iter);
				retval++;
			}
		}
		fprintf(stderr, "Usunięto %d leków związanych z kategorią %s\n",retval,kategoria);
		Queue_iterator_Init(&iter,baza_lekow->kategorie);
		char* tmp;
		while((tmp=Queue_next(&iter))!=NULL){
			if(strcmp(tmp,kategoria)==0){
                		Queue_remove(&iter);
			}
		}     
		return retval;
	}
	else
	{
		fprintf(stderr, "Kategoria %s nie istnieje!\n",kategoria);
		return -1;
	}
}

int wyswietl_liste_lekow(baza_lekow* baza_lekow)
{
	int index=1;
	int liczba_lekow=baza_lekow->leki->sizeOfQueue;
	printf("Baza Leków zawiera %d wpisów\n", liczba_lekow);
	Queue_iterator iter;
	Queue_iterator_Init(&iter,baza_lekow->leki);
	lek *lek=NULL;
	while((lek=Queue_next(&iter))!=NULL)
	{
		printf("[%2d/%2d] Nazwa Leku: %s\tKategoria Leku: %s\n",index++, liczba_lekow, lek->nazwa, lek->kategoria);
	}
}

int wyswietl_liste_kategorii(baza_lekow* baza_lekow)
{
	int index=1;
	int liczba_kategorii=baza_lekow->kategorie->sizeOfQueue;
	printf("Baza Leków zawiera %d kategori\n", liczba_kategorii);
	Queue_iterator iter;
	Queue_iterator_Init(&iter,baza_lekow->kategorie);
	char *kategoria=NULL;
	while((kategoria=Queue_next(&iter))!=NULL)
	{
		printf("[%2d/%2d] Nazwa Kategoria: %s\n",index++, liczba_kategorii, kategoria);
	}
}

int wczytaj_baze_lekow(baza_lekow* baza_lekow,FILE *plik,FLAG flag)
{
	if (flag==TXT)
	{
		lek lek;
		while(fscanf(plik,"%"ROZMIAR_str"s;%"ROZMIAR_str"%s\n",lek.nazwa,lek.kategoria)!=EOF)
		{
			if(sprawdz_kategorie(baza_lekow,lek.kategoria)==0)
			{
				dodaj_kategorie(baza_lekow,lek.kategoria);
			}
			dodaj_lek(baza_lekow,lek);			
		}
	}
	else //binary
	{
		lek lek;
		while(fread(&lek,sizeof(lek),1,plik)!=EOF)
		{
			if(sprawdz_kategorie(baza_lekow,lek.kategoria)==0)
			{
				dodaj_kategorie(baza_lekow,lek.kategoria);
			}
			dodaj_lek(baza_lekow,lek);
		}
		
	}
}

int zapisz_baze_lekow(baza_lekow* baza_lekow,FILE* plik,FLAG flag)
{
	Queue_iterator iter;
	Queue_iterator_Init(&iter,baza_lekow->leki);
	lek *lek=NULL;
	if (flag==TXT)
	{
		while((lek=Queue_next(&iter))!=NULL)
		{
			fprintf(plik,"%"ROZMIAR_str"s;%"ROZMIAR_str"s\n",lek->nazwa,lek->kategoria);
		}
	}
	else //binary
	{
		while((lek=Queue_next(&iter))!=NULL)
		{
			fwrite(lek,sizeof(lek),1,plik);
		}
	}
}

int zwolnij_baze_lekow(baza_lekow* baza_lekow)
{
	Queue_clean(baza_lekow->kategorie);
	Queue_clean(baza_lekow->leki);
	free(baza_lekow);
	baza_lekow=NULL;
}

int zainicjuj_baze_lekow(baza_lekow* baza_lekow)
{
	//baza_lekow=malloc(sizeof(baza_lekow));
	baza_lekow->kategorie=malloc(sizeof(Queue));
	baza_lekow->leki=malloc(sizeof(Queue));
	Queue_Init(baza_lekow->kategorie,sizeof(char[ROZMIAR]));
	Queue_Init(baza_lekow->leki,sizeof(lek));
}
