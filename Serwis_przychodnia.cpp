// Serwis przychodnia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Pacjent.h"
#include "Doktor.h"
#include "Wizyta.h"

vector<Pacjent> pacjenci;
vector<Doktor> doktorzy;


void rejestracja()
{
    int pesel_rejestracja;
    string imie_rejestracja, nazwisko_rejestracja;
    bool pacjent_istnieje = 0;
    cout << "Podaj PESEL" << endl;
    cin >> pesel_rejestracja;
    cout << "Podaj imie" << endl;
    cin >> imie_rejestracja;
    cout << "Podaj nazwisko" << endl;
    cin >> nazwisko_rejestracja;
    for (int i = 0; i < pacjenci.size(); i++)
    {
        if (pacjenci[i].getPesel() == pesel_rejestracja)
        {
            cout << "Pacjent juz zostal zarejestrowany" << endl;
            pacjent_istnieje = 1;
        }
    }
    if (pacjent_istnieje == 0)
    {
        Pacjent nowy_pacjent(imie_rejestracja, nazwisko_rejestracja, pesel_rejestracja);
        pacjenci.push_back(nowy_pacjent);
        cout << "Utworzono pacjenta" << endl;
    }
}

void rejestracja_doktora()
{
    int pesel_rejestracja;
    string imie_rejestracja, nazwisko_rejestracja, specjalizacja_rejestracja;
    bool doktor_istnieje = 0;
    cout << "Podaj PESEL" << endl;
    cin >> pesel_rejestracja;
    cout << "Podaj imie" << endl;
    cin >> imie_rejestracja;
    cout << "Podaj nazwisko" << endl;
    cin >> nazwisko_rejestracja;
    cout << "Podaj specjalizacje" << endl;
    cin >> specjalizacja_rejestracja;
    for (int i = 0; i < doktorzy.size(); i++)
    {
        if (doktorzy[i].getPesel() == pesel_rejestracja)
        {
            cout << "Doktor juz zostal zarejestrowany" << endl;
            doktor_istnieje = 1;
        }
    }
    if (doktor_istnieje == 0)
    {
        Doktor nowy_doktor(imie_rejestracja, nazwisko_rejestracja, pesel_rejestracja, specjalizacja_rejestracja);
        doktorzy.push_back(nowy_doktor);
        cout << "Utworzono doktora" << endl;
    }
}

void umowWizyte()
{
    string szukana_specjalizacja;
    int planowany_dzien, planowana_godzina, pesel_pacjenta;
    cout << "Podaj specjalizację lekarza:" << endl;
    cin >> szukana_specjalizacja;
    cout << "Podaj dzien wizyty" << endl;
    cin >> planowany_dzien;
    cout << "Podaj godzine wizyty" << endl;
    cin >> planowana_godzina;
    cout << "Podaj pesel pacjenta" << endl;
    cin >> pesel_pacjenta;
    for (int i = 0; i < doktorzy.size(); i++)
    {
        if (doktorzy[i].getspecjalizacja() == szukana_specjalizacja)
        {
            if (doktorzy[i].czyTerminWolny(planowany_dzien, planowana_godzina) == true)
            {
                //umowienie wizyty
                doktorzy[i].ustawWizyteWTerminarzu(planowany_dzien, planowana_godzina, pesel_pacjenta);
                cout << "umowiono wizyte hura" << endl;
                break;
            }
        }
        if (i == doktorzy.size() - 1)
        {
            cout << "Prosze podać inny termin - brak dostepnych lekarzy we wskazanym terminie" << endl;
            umowWizyte();
            //break;
        }
    }
}

void wybierz_dzialanie()
{
    string dzialanie;
    cout << "Wybierz dzialanie: P - rejestracja pacjenta, D - rejestracja doktora, W - umow wizyte, Z - zmien termin wizyty" << endl;
    cin >> dzialanie;
    if (dzialanie == "P") { rejestracja(); }
    if (dzialanie == "D") { rejestracja_doktora(); }
    if (dzialanie == "W") { umowWizyte(); }

}

int main()
{
    while (true)
    {
        wybierz_dzialanie();
        //funkcja odpowiedzialna za odczytanie danych
        //funkcja odpowiedzialna za odpalenie wlaściwej akcji
    }
    
}


























// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
