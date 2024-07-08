#include "UzytkownikMenager.h"

void UzytkownikMenager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenager::czyIstniejeLogin(string login)
{
    for (size_t i = 0; i < uzytkownicy.size(); i++ )
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            Sleep(600);
            return true;
        }
    }
    return false;
}

void UzytkownikMenager::wypiszWszystkichUzytkownikow()
{
    for (size_t i = 0; i < uzytkownicy.size(); i++ )
    {
      cout << uzytkownicy[i].pobierzId() << endl;
      cout << uzytkownicy[i].pobierzLogin() << endl;
      cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikMenager::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    idZalogowanegoUzytkownika = 0;
    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    for (size_t i = 0; i < uzytkownicy.size(); i++ )
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    this->idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
int UzytkownikMenager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

bool UzytkownikMenager::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika != 0)
    {
        return true;
    }
    return false;
}

void UzytkownikMenager::wylogujUzytkownika()
{
    if (czyUzytkownikJestZalogowany())
    {
       idZalogowanegoUzytkownika = 0;
    }
}

void UzytkownikMenager::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (size_t i = 0; i < uzytkownicy.size(); i++ )
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
