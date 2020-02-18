#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#include"Nagowek.h"
Produkty* dodaj_produkt(Produkty* pierwszy_produkt)//Dodawanie produktow
{
    Produkty* bierzacy_produkt =malloc(sizeof(Produkty));
     if(bierzacy_produkt == NULL)
    {
        printf("brak miejsca \n");
        exit(0);
    }
    char nazwa_tymczasowa[MAX];
    float cena_tymczasowa;
    int rodzaj_tymczasowy;
    printf("Podaj nazwe produktu \n");
    scanf("%19s", nazwa_tymczasowa);
    bierzacy_produkt->nazwa =malloc((strlen(nazwa_tymczasowa)+1)*sizeof(char));
      if(bierzacy_produkt->nazwa == NULL)
    {
        printf("brak miejsca \n");
        exit(0);
    }
    strcpy(bierzacy_produkt->nazwa, nazwa_tymczasowa);
    printf("Podaj cene produktu \n");
    scanf("%f", &cena_tymczasowa);
    bierzacy_produkt->cena = cena_tymczasowa;
    printf("Podaj rodzaj produktu: \n 1 - OWOC \n 2- WARZYWO\n 3 - MIESO\n 4 - NABIAL \n");
    scanf("%d", &rodzaj_tymczasowy);
    bierzacy_produkt->rodzaj = rodzaj_tymczasowy;
    bierzacy_produkt->nastepny = pierwszy_produkt;
    return bierzacy_produkt;

}

Produkty* Wypisz(Produkty* pierwszy_produkt)//Wypisywanie Produktow
{
    Produkty* bierzacy_produkt = pierwszy_produkt;
    int wybor_wyswietlania;
    menu_wybor();
    wybor_wyswietlania =  wprowadz();

        switch(wybor_wyswietlania)
        {
        case 1://Wypisuje wszystkie produkty
             do
           {
           wypisz_1(bierzacy_produkt);
           bierzacy_produkt = bierzacy_produkt->nastepny;
           }while(bierzacy_produkt != NULL);
           break;
        case 2: // wypisuje Owoce
            do
            {
            if(bierzacy_produkt->rodzaj == 1)
            {
               wypisz_1(bierzacy_produkt);
            }
              bierzacy_produkt = bierzacy_produkt->nastepny;
            }while(bierzacy_produkt != NULL);

            break;
        case 3: // wypisuje Warzywa
            do
            {
            if(bierzacy_produkt->rodzaj == 2)
            {
               wypisz_1(bierzacy_produkt);
            }
              bierzacy_produkt = bierzacy_produkt->nastepny;
            }while(bierzacy_produkt != NULL);

             break;
        case 4: // wypisuje Mieso
            do
            {
            if(bierzacy_produkt->rodzaj == 3)
            {
               wypisz_1(bierzacy_produkt);
            }
              bierzacy_produkt = bierzacy_produkt->nastepny;
            }while(bierzacy_produkt != NULL);

            break;
        case 5: // wypisuje Nabial
            do
            {
            if(bierzacy_produkt->rodzaj == 4)
            {
               wypisz_1(bierzacy_produkt);
            }
              bierzacy_produkt->nastepny;
            }while(bierzacy_produkt != NULL);

             break;
        }
}
Produkty* Usun(Produkty* pierwszy_produkt)//Usuwanie Produktu
{
    Produkty* bierzacy_produkt = pierwszy_produkt;
    Produkty* poprzedni_element=NULL;
    char nazwa_tymczasowa[MAX];
    printf("Podaj nazwe usuwanego produktu: \n");
    scanf("%19s", nazwa_tymczasowa);
    do
    {
        if(porownaj(bierzacy_produkt, nazwa_tymczasowa) == 1)
        {
            if(bierzacy_produkt==pierwszy_produkt) pierwszy_produkt = bierzacy_produkt->nastepny;
            else poprzedni_element->nastepny = bierzacy_produkt->nastepny;
            free(bierzacy_produkt);
        	return pierwszy_produkt;
        }

        poprzedni_element = bierzacy_produkt;
        bierzacy_produkt = bierzacy_produkt->nastepny;
    }while(bierzacy_produkt != NULL);

    return pierwszy_produkt;
}

int porownaj(Produkty* bierzacy_produkt,char nazwa_tymczasowa[])//Porownanie nazw
{
    int a = 0;
    int b = strlen(nazwa_tymczasowa);

    for(int i = 0; i<b-1; i++)
    {

        if(bierzacy_produkt->nazwa[i] != nazwa_tymczasowa[i])
           {
             a =0;
            break;
           }

        else a = 1;
    }

    return a;
}
void Posortuj(Produkty* pierwszy_produkt)//Sortowanie elemntow listy - cena rosn¹co
{
    Produkty* Bierzacy = pierwszy_produkt;
    Produkty* tymczasowy = NULL;
    Produkty* it = pierwszy_produkt;
    int a = 1;
     while(a)
    {
     a = 0;
    for(Bierzacy = pierwszy_produkt ;Bierzacy->nastepny->nastepny!=0; Bierzacy = Bierzacy->nastepny)

        if(Bierzacy->nastepny->cena > Bierzacy->nastepny->nastepny->cena)
        {
            a = 1;
            tymczasowy = Bierzacy->nastepny->nastepny;
            Bierzacy->nastepny->nastepny = Bierzacy->nastepny->nastepny->nastepny;
            tymczasowy->nastepny = Bierzacy->nastepny;
            Bierzacy->nastepny = tymczasowy;
         }
    }

}
