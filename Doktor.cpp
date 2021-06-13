#include "Doktor.h"
#include <fstream>

void Doktor::zapiszPlikDoktora(Doktor zapisywany_doktor)
{
    ofstream plikDoktora;
    plikDoktora.open("C:\\Users\\Easyd\\Desktop\\serwis przychodnia\\Serwis przychodnia\\plikDoktora.txt");
    plikDoktora << zapisywany_doktor.getImie() << endl;
    plikDoktora << zapisywany_doktor.getNazwisko() << endl;
    plikDoktora << zapisywany_doktor.getPesel() << endl;
    plikDoktora << zapisywany_doktor.getspecjalizacja() << endl;
    plikDoktora.close();
}

int Doktor::getPesel()
{
    return pesel;
}

string Doktor::getImie()
{
    return imie;
}

string Doktor::getNazwisko()
{
    return nazwisko;
}

string Doktor::getspecjalizacja()
{
    return specjalizacja;
}

Doktor::Doktor(string imie_doktora, string nazwisko_doktora, int pesel_doktora, string specjalizacja_doktora)
{
    imie = imie_doktora;
    nazwisko = nazwisko_doktora;
    pesel = pesel_doktora;
    specjalizacja = specjalizacja_doktora;
}

Doktor::Doktor()
{
}

bool Doktor::czyTerminWolny(int dzien, int godzina)
{
    if (terminarz.dostepnosc[dzien][godzina] == 0)
    {
        return true;
    }
    else { return false; }
}

void Doktor::ustawWizyteWTerminarzu(int dzien, int godzina, int pesel)
{
    terminarz.dodajWizyte(dzien, godzina, pesel);
    ofstream plikDoktora;
    plikDoktora.open("C:\\Users\\Easyd\\Desktop\\serwis przychodnia\\Serwis przychodnia\\plikDoktora.txt", ios::app);
    for (int i = 0; i < 30; i++)
    {
        for (int it = 0; it < 7; it++)
        {
            plikDoktora << terminarz.dostepnosc[i][it] << " ";
        }
        plikDoktora << endl;
    }
}

int Doktor::usunWizyteWTerminarzu(int dzien, int godzina)
{
    return terminarz.usunWizyte(dzien, godzina);
}

