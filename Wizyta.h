#pragma once

#include <string>
#include "Pacjent.h"
#include "Doktor.h"

class Wizyta
{
	Pacjent pacjent;
	Doktor doktor;
	int dzien;
	int godzina;
	//string specjalizacja;
	string status;
public:
	Pacjent getPacjent();
	Doktor getDoktor();
	int getDzien();
	int getGodzina();
	Wizyta();
};

