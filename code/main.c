#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#include"Nagowek.h"
int main()
{
    int wybor;
    Produkty* pierwszy_produkt = NULL;
    do
    {
        Menu(pierwszy_produkt);
        wybor = wprowadz();
        switch(wybor)
        {
            case 1:
                pierwszy_produkt = dodaj_produkt(pierwszy_produkt);
                break;
            case 2:
                Wypisz(pierwszy_produkt);
                break;
            case 3:
                Usun(pierwszy_produkt);
                break;
            case 4:
                Edytuj(pierwszy_produkt);
                break;
            case 5:
                Szykaj_ceny(pierwszy_produkt);
                break;
            case 6:
               Posortuj(pierwszy_produkt);
              break;
        }
    }while(wybor != 0);
}
