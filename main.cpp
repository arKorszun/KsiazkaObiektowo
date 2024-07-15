#include <iostream>

#include "KsiazkaAdresowa.h"
#include "UzytkownikMenager.h"


using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
   // ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
   // ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
   // ksiazkaAdresowa.wylogujUzytkownika();
    // ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlkWszystkichAdresatow();

    return 0;
}
