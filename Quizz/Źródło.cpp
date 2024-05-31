#include <iostream>
#include "pytania.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm> // Do std::transform lower case upper case



using namespace std;

void Pytanie::wczytaj()
{
    fstream plik;
    plik.open("tresc.txt", ios::in);

    if (plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku!";
        exit(0);
    }

    int nr_linii = (nr_pytania - 1) * 6 + 1;
    int aktualny_nr = 1;
    string linia;

    while (getline(plik, linia))
    {
        if (aktualny_nr == nr_linii) tresc = linia;
        if (aktualny_nr == nr_linii + 1) a = linia;
        if (aktualny_nr == nr_linii + 2) b = linia;
        if (aktualny_nr == nr_linii + 3) c = linia;
        if (aktualny_nr == nr_linii + 4) d = linia;
        if (aktualny_nr == nr_linii + 5) poprawna = linia;
        aktualny_nr++;
    }

    plik.close();

}

void Pytanie::zadaj()
{
    cout << endl << tresc << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << "------------------------" << endl;
    cout << endl << "Odpowiedz: ";
    cin >> odpowiedz;
}

void Pytanie::sprawdz()
{
    // Konwersja odpowiedzi u¿ytkownika i poprawnej odpowiedzi na ma³e litery
    string poprawna_lower = poprawna;
    string odpowiedz_lower = odpowiedz;

    transform(poprawna_lower.begin(), poprawna_lower.end(), poprawna_lower.begin(), ::tolower);
    transform(odpowiedz_lower.begin(), odpowiedz_lower.end(), odpowiedz_lower.begin(), ::tolower);

    if (odpowiedz_lower == poprawna_lower)
    {
        punkt = 1;
    }
    else
    {
        punkt = 0;
    }
}