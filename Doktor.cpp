#include "Doktor.h"
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
}
