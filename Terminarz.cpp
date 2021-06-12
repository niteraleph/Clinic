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
