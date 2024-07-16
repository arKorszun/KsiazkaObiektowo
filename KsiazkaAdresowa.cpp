#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();
    adresatMenager.ustawIdZalogowanegoUzytkownika(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
    adresatMenager.wczytajAdresatowZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenager.wylogujUzytkownika();
    adresatMenager.wyczyscWektorAdresaci();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenager.dodajAdresata();
}

void KsiazkaAdresowa::wyswietlkWszystkichAdresatow()
{
    adresatMenager.wyswietlWszystkichAdresatow();
}


