#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include "Adresat.h"
#include "PlikZAdresatami.h"


using namespace std;

class AdresatMenager
{
    PlikZAdresatami plikZAdresatami;

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);


public:
    AdresatMenager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };


    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyszukajAdresatowPoImieniu();



};

#endif // ADRESATMENAGER_H
