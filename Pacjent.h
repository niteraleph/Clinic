#pragma once
#include <string>

using std::string;

class Pacjent
{
	int pesel;
	string imie, nazwisko;
public:
	int getPesel();
	string getImie();
	string getNazwisko();
	Pacjent(string imie_pacjenta, string nazwisko_pacjenta, int pesel_pacjenta);
	Pacjent();
};

