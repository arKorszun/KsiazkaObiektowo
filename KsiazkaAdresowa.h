#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>
#include "UzytkownikMenager.h"
#include "AdresatMenager.h"
#include "MetodyPomocnicze.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenager uzytkownikMenager;
    AdresatMenager *adresatMenager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenager = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenager;
        adresatMenager = NULL;
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyszukajAdresatowPoImieniu();

    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();



};
#endif
