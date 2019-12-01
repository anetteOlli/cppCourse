#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

//Assigment1: taskB main.cpp

/*
 * Les inn temperaturene fra en fil og lagre dem i en tabell før du begynner opptellingen.
 * Innlesingen fra fil skal ligge i en funksjon med følgende prototyp (deklarasjon):

void read_temperatures(double temperatures[], int length);
Denne skal du sette opp foran main(), mens funksjonsdefinisjonen skal plasseres etter main() i filen din:

void read_temperatures(double temperatures[], int length) {
   // her plasserer du koden i funksjonen, vi sier at vi definerer funksjonen
}
Du kaller funksjonen på følgende måte fra main():

read_temperatures(temperatures, length);
Funksjonen skal åpne filen, lese inn temperaturene og lagre dem i tabellen temperatures, og endelig lukke filen.

Kompilatoren forholder seg til funksjonsdeklarasjonen, mens lenkeren trenger funksjonsdefinisjonen.
 Det er også mulig å plassere funksjonsdefinisjonen foran main() (i stedet for prototypen),
 fordi en definisjon også er en deklarasjon (men en deklarasjon er ikke en definisjon).
 Filene du inkluderer med #include inneholder i hovedsak funksjonsprotyper.
 */


//prototype:
void read_temperatures(double temperatures[], int length);

int main() {
    const int length = 5;
    double temperatures[length];


    read_temperatures(temperatures, length);

    for (int i = 0; i < length; i++) {
        cout << "lest inn temperatur: " << temperatures[i] << endl;
    }
    return 0;
}


void read_temperatures(double temperatures[], int length) {

    const char filename[] = "../testdata.dat";
    ifstream file;
    file.open(filename);
    if( !file ) {
        cout << "Feil ved åpning av innfil." << endl;
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < length; i++ ) {
        file >> temperatures[i];
    }
    file.close();


}
