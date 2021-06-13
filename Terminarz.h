#pragma once

class Terminarz
{
public:
	int dostepnosc [31][8]; //0 lub null oznacza brak wizyty, jeżeli wartosc jest uzupelniona to jest to pesel pacjenta
	Terminarz();
	void dodajWizyte(int dzienWizyty, int godzinaWizyty, int peselPacjenta);
	int usunWizyte(int dzienWizyty, int godzinaWizyty);

};

