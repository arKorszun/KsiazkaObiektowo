#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Adresat.h"
#include "PlikZAdresatami.h"


using namespace std;

class AdresatMenager
{
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;


public:
    AdresatMenager(string nazwaPlikuZAdresatami)
    : plikZAdresatami(nazwaPlikuZAdresatami){};

    void wczytajAdresatowZPliku();
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void ustawIdZalogowanegoUzytkownika(int id);
    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);

};

#endif // ADRESATMENAGER_H
