#ifndef NAGOWEK_H_INCLUDED
#define NAGOWEK_H_INCLUDED

/**Typ obliczeniowy okreslajacy rodzaj produktu*/enum Rodzaj{OWOC=1, WARZYWO, MIESO, NABIAL};
/**Struktury Produktow*/struct Produkty//Strunkura produktu
{
    char* nazwa;
    enum Rodzaj rodzaj;
    float cena;
    struct Produkty* nastepny;

};

typedef struct Produkty Produkty;
/**Funkcja wyswietlajaca funkcjonalnosc ktora moze wybrac uzytkownik
  @param -wskaznik na pierwszy element listy*/void Menu(Produkty* pierwszy_produkt);
/**Funkcja umozliwiajaca wczytanie numer od uzytkownika

 @return -Podprogram zwraca wartosc podana przez urzytkownika*/int wprowadz(void);
/** Dodaje produkty do listy
  @param -wskaznik na pierwszy element listy
  @return -nowy  element lisy */Produkty* dodaj_produkt(Produkty* pierwszy_produkt);
/**Wypisuje produkty znajdujace sie w liscie
 @param -wskaznik na pierwszy element listy*/Produkty* Wypisz(Produkty* pierwszy_produkt);
/**Funkcja wysietlajaca pojedynczy element
 @param -wskaznik na pierwszy element listy*/void wypisz_1(Produkty* bierzacy_produkt);
/**Funkcja usuwa produkt o nazwie podanej przez urzytkownika
  @param -wskaznik na pierwszy element listy
  @return -zwraca nowa liste
  */Produkty* Usun(Produkty* pierwszy_produkt);
/**Funkcja porownujaca napisy (podany przez uzytkownika i z listy)
  @param -wskaznik na pierwszy element listy i napis podany przez uzytkownika
 @return  -1 gdy dwa stringi sa takie same i 0 gdy sa rozne
 */int porownaj(Produkty* bierzacy_produkt, char nazwa_tymczasowa[]);
/**Funkcja umozliwiajaca edytowanie ceny
 @param -wskaznik na pierwszy element listy*/void Edytuj(Produkty* pierwszy_produkt);
/**Funkcja szukajaca ceny produktu o podanej nazwie
 @param -wskaznik na pierwszy element listy*/void Szykaj_ceny(Produkty* pierwszy_produkt);
/**Funkcja sortujaca produkty po cenie
 @param -wskaznik na pierwszy element listy*/void Posortuj(Produkty* pierwszy_produkt);
/**Funkcja wypisujaca rodzaje produktu*/void menu_wybor();


#endif // NAGOWEK_H_INCLUDED
