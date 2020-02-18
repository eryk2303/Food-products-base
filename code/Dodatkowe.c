#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#include"Nagowek.h"
void Menu(Produkty* pierwszy_produkt)//Wybor funkcji
{
    printf("1 - Dodaj nowy produkt \n");
    if(pierwszy_produkt != NULL)
    {
        printf("2 - Wyswietl produkty \n");
        printf("3 - Usun element \n");
        printf("4 - Edytuj cene \n");
        printf("5 - Wyszukaj cene produktu \n");
        printf("6 - Sortowanie Produktow \n");
    }
    printf("0 - Zakoncz program \n");
}

int wprowadz(void)//Odczyt danych wprowadzonych przez urzytkownika
{
    int wybor;
    scanf("%d", &wybor);
    return wybor;
}
void wypisz_1(Produkty* bierzacy_produkt)//Wypiszywanie Elementow struktury
{
    printf("Nazwa: %s \n", bierzacy_produkt->nazwa);
    printf("Cena: %.2f \n", bierzacy_produkt->cena);
}

void menu_wybor()//Opcje wyswietlania
{
    printf("1 - Wszystko \n");
    printf("2 - Owoce \n");
    printf("3 - Warzywa \n");
    printf("4 - Mieso \n");
    printf("5 - Nabial \n");
}
void Edytuj(Produkty* pierwszy_produkt)//Edytowanie cenny produktu
{
    Produkty* bierzacy_produkt = pierwszy_produkt;
    float nowa_cena;
    char nazwa_tymczasowa[MAX];
    printf("Podaj nazwe edytowanego produktu: \n");
    scanf("%19s", nazwa_tymczasowa);

    do
    {
        if(porownaj(bierzacy_produkt, nazwa_tymczasowa) == 1)
        {
            printf("Podaj nowa cene \n");
            scanf("%f", &nowa_cena);
            bierzacy_produkt->cena = nowa_cena;
        }
    bierzacy_produkt = bierzacy_produkt->nastepny;
    }while(bierzacy_produkt != NULL);
}

void Szykaj_ceny(Produkty* pierwszy_produkt)//Wyszukanie cenny produktu
{
    Produkty* bierzacy_produkt = pierwszy_produkt;
    float nowa_cena;
    char nazwa_tymczasowa[MAX];
    printf("Podaj nazwe szukanego produktu: \n");
    scanf("%19s", nazwa_tymczasowa);

    do

    {
        if(porownaj(bierzacy_produkt, nazwa_tymczasowa) == 1)
        {
            printf("Cena tego produktu %.2f \n",bierzacy_produkt->cena);

        }
    bierzacy_produkt = bierzacy_produkt->nastepny;
    }while(bierzacy_produkt != NULL);

}


