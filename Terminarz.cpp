#include "Terminarz.h"
#include <string>

using namespace std;

Terminarz::Terminarz()
{
	for (int i = 0; i < 30; i++)
	{
		for (int it = 0; it < 7; it++)
		{
			dostepnosc[i][it] = 0;
		}
	}
}

void Terminarz::dodajWizyte(int dzienWizyty, int godzinaWizyty,int peselPacjenta)
{
	dostepnosc[dzienWizyty][godzinaWizyty] = peselPacjenta;
}

int Terminarz::usunWizyte(int dzienWizyty, int godzinaWizyty)
{
	int pesel_pacjenta = dostepnosc[dzienWizyty][godzinaWizyty];
	dostepnosc[dzienWizyty][godzinaWizyty] = 0;
	return pesel_pacjenta;
}

