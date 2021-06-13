// Serwis przychodnia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Pacjent.h"
#include "Doktor.h"
#include "Wizyta.h"

using namespace std;

vector<Pacjent> pacjenci;
vector<Doktor> doktorzy;
string uzytkownik;
const string haslo_dyrektora = "iqos";


void wczytajDoktora()
{
    string wczytywana_dostepnosc[31][8];
    ifstream plikDoktora;
    plikDoktora.open("plikDoktora.txt");
    string linieTekstu [35]; //4 linie zawierajace imie, nazwisko, pesel, specjalizacje oraz 31 linii reprezentujących wizyty
    int i = 0;
    while (getline(plikDoktora, linieTekstu[i])) {
        i++;
    }
    Doktor wczytywany_doktor(linieTekstu[0], linieTekstu[1], stoi(linieTekstu[2]), linieTekstu[3]);
    i = 4;
    int it = 0;
    for (i; i < 35; i++)
    {
        istringstream liniaTekstu(linieTekstu[i]);
        while (getline(liniaTekstu, wczytywana_dostepnosc[i+4][it])) {
            it++;
        }
    }
    cout << "abc";
}



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
        nowy_doktor.zapiszPlikDoktora(nowy_doktor);
        cout << "Utworzono doktora" << endl;
    }
}

void umowWizyte()
{
    string szukana_specjalizacja;
    int planowany_dzien, planowana_godzina, pesel_pacjenta;
    cout << "Podaj specjalizacje lekarza:" << endl;
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

void usunWizyte()
{
    int pesel_doktora, dzien_usuwanej_wizyty, godzina_usuwanej_wizyty;
    cout << "Podaj pesel doktora" << endl;
    cin >> pesel_doktora;
    cout << "Podaj dzien anulowanej wizyty" << endl;
    cin >> dzien_usuwanej_wizyty;
    cout << "Podaj godzine anulowanej wizyty" << endl;
    cin >> godzina_usuwanej_wizyty;
    for (int i = 0; i < doktorzy.size(); i++)
    {
        if (doktorzy[i].getPesel() == pesel_doktora)
        {
            doktorzy[i].usunWizyteWTerminarzu(dzien_usuwanej_wizyty, godzina_usuwanej_wizyty);
        }
        cout << "Pomyslnie anulowano wizyte" << endl;
    }
}

void zmienTerminWizyty()
{
    int pesel_doktora, stary_dzien_wizyty, stara_godzina_wizyty, nowy_dzien_wizyty, nowa_godzina_wizyty, pesel_pacjenta;
    cout << "Podaj pesel doktora" << endl;
    cin >> pesel_doktora;
    cout << "Podaj stary dzien wizyty" << endl;
    cin >> stary_dzien_wizyty;
    cout << "Podaj stara godzine wizyty" << endl;
    cin >> stara_godzina_wizyty;
    cout << "Podaj nowy dzien wizyty" << endl;
    cin >> nowy_dzien_wizyty;
    cout << "Podaj nowa godzine wizyty" << endl;
    cin >> nowa_godzina_wizyty;
    for (int i = 0; i < doktorzy.size(); i++)
    {
        if (doktorzy[i].getPesel() == pesel_doktora)
        {
            pesel_pacjenta = doktorzy[i].usunWizyteWTerminarzu(stary_dzien_wizyty, stara_godzina_wizyty);
            doktorzy[i].ustawWizyteWTerminarzu(nowy_dzien_wizyty, nowa_godzina_wizyty, pesel_pacjenta);
        }
    }

}

void logowanie()
{
    string haslo;
    cout << "Czy jestes (R) recepcjonista czy (D) dyrektorem?" << endl;
    cin >> uzytkownik;
    if (uzytkownik == "D")
    {
        do
        {
            cout << "Wpisz haslo dyrektora" << endl;
            cin >> haslo;
        } while (haslo != haslo_dyrektora);
    }
}

void wybierz_dzialanie(string obecny_uzytkownik)
{
    string dzialanie;
    if (uzytkownik == "R")
    {
        cout << "Wybierz dzialanie: P - rejestracja pacjenta, W - umow wizyte, Z - zmien termin wizyty, A - Anuluj wizyte" << endl;
        cin >> dzialanie;
        if (dzialanie == "P") { rejestracja(); }
        if (dzialanie == "W") { umowWizyte(); }
        if (dzialanie == "A") { usunWizyte(); }
        if (dzialanie == "Z") { zmienTerminWizyty(); }
    }
    else
    {
        cout << "Wybierz dzialanie: D - zarejestruj doktora" << endl;
        cin >> dzialanie;
        if (dzialanie == "D") { rejestracja_doktora(); }
    }
}

int main()
{
    //wczytajDoktora();
    while (true)
    {
        logowanie();
        wybierz_dzialanie(uzytkownik);
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
