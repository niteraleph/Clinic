#pragma once
#include <string>
#include "Terminarz.h"

using namespace std;
class Doktor
{
	int pesel;
	string imie;
	string nazwisko;
	string specjalizacja;
	Terminarz terminarz;
public:
	int getPesel();
	string getImie();
	string getNazwisko();
	string getspecjalizacja();
	Doktor(string imie_doktora, string nazwisko_doktora, int pesel_doktora, string specjalizacja_doktora);
	Doktor();
	bool czyTerminWolny(int dzien, int godzina);
	void ustawWizyteWTerminarzu(int dzien, int godzina, int pesel);
};

