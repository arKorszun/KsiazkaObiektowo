#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;


    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
#endif
