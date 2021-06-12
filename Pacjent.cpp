#include "Pacjent.h"


int Pacjent::getPesel()
{
    return pesel;
}

string Pacjent::getImie()
{
    return imie;
}

string Pacjent::getNazwisko()
{
    return nazwisko;
}

Pacjent::Pacjent(string imie_pacjenta, string nazwisko_pacjenta, int pesel_pacjenta)
{
    imie = imie_pacjenta;
    nazwisko = nazwisko_pacjenta;
    pesel = pesel_pacjenta;
}

Pacjent::Pacjent()
{

}

