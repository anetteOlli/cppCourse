#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//Assigment 9, main.cpp

/*
OPPGAVETEKST:
I denne øvingen trenger du flere STL-algoritmer enn de som er gjennomgått i leksjonen. Bruk læreboka og/eller STL-referansene på http://www.cplusplus.com/reference/algorithm eller https://en.cppreference.com/w/cpp/algorithm

Bruk vektorne v1 og v2 fra leksjonen. Et av argumentene i algoritmene dere bruker (find_if, equal, replace_copy_if) skal være en anonym funksjon.

a) Finn første element i v1 som er større enn 15 ved hjelp av find_if. Tips: Den logiske funksjonen skal ta ett argument og returnere true dersom dette er større enn 15.

b) Vi definerer "omtrent lik" til å bety at forskjellen mellom to verdier ikke er mer enn 2. Finn ut om intervallet [v1.begin(), v1.begin() + 5> og v2 er like i denne betydningen av likhet. Hva med intervallet [v1.begin(), v1.begin() + 4>? Bruk algoritmen equal.

c) Erstatt alle oddetall i v1 med 100 ved hjelp av replace_copy_if.


*/

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    // Søker etter enkeltverdi med find()
    auto pos = find(v1.begin(), v1.end(), 25);
    if (pos != v1.end()) {
        cout << "25 fins i v1 på indeks " << (pos - v1.begin()) << endl;
    } else
        cout << "25 fins ikke i v1" << endl;

    auto start = v1.begin() + 2;
    auto end = v1.end() - 2;
    cout << "Søker i en del av tabellen: ";
    for (auto it = start; it != end; ++it)
        cout << *it << " ";
    cout << endl;
    pos = find(start, end, 14);
    if (pos != end) {
        cout << "14 fins i v1 på indeks " << (pos - v1.begin()) << endl;
    } else
        cout << "14 fins ikke i v1" << endl;

    // Søker etter den første blant flere, find_first_of()
    // Søker i v1 {3, 3, 12, 14, 17, 25, 30} etter den første av
    // {12, 14, 24} (en del av v2). Svaret skal bli 2
    pos = find_first_of(v1.begin(), v1.end(), v2.begin() + 2, v2.end());
    cout << "Første på indeks " << (pos - v1.begin()) << endl;

    // Søker etter to like, ved siden av hverandre, adjacent_find()
    pos = adjacent_find(v1.begin(), v1.end());
    cout << "Finner to like på indeks " << (pos - v1.begin()) << endl;

    // Teller antall 3-tall i v1
    cout << "v1 inneholder " << count(v1.begin(), v1.end(), 3) << " 3-tall" << endl;

    // Finner største verdi i v1 (max_element returnerer en iterator)
    cout << "Største verdi i v1 er " << *max_element(v1.begin(), v1.end()) << endl; // dereferanse


    /*OPPGAVE:
     * a) Finn første element i v1 som er større enn 15 ved hjelp av find_if.
     * Tips: Den logiske funksjonen skal ta ett argument og returnere true dersom dette er større enn 15.
     */
    pos = find_if(start, end, [](int &x) { return x > 15; });
    if (pos != end) {
        cout << "første element som er større enn 15 er: " << v1.at(pos - v1.begin()) << endl;
    } else {
        cout << "Fant ingen elementer som er større enn 15" << endl;
    }

    /*
     * b)
     *  Vi definerer "omtrent lik" til å bety at forskjellen mellom to verdier ikke er mer enn 2.
     *  Finn ut om intervallet [v1.begin(), v1.begin() + 5> og v2 er like i denne betydningen av likhet.
     *  Hva med intervallet [v1.begin(), v1.begin() + 4>? Bruk algoritmen equal.
     */
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    if( equal(v1.begin(), v1.begin()+5,v2.begin(), [](int &x, int &y){ return abs(x-y) < 2;}) ) {
        cout << "de fem første elementene er like" << endl;
    } else {
        cout << "de fem første elementene er ulike " << endl;
    }
    if( equal(v1.begin(), v1.begin() +4, v2.begin(), [](int &x, int &y){ return abs(x-y) < 2;}) ) {
        cout << "de fire første elementene er like" << endl;
    } else {
        cout << "de fire første elementene er ulike" << endl;
    }



    /*
     * c) Erstatt alle oddetall i v1 med 100 ved hjelp av replace_copy_if.
     */
    cout << "v1: " << v1 << endl;
    replace_copy_if(v1.begin(), v1.end(), v1.begin(), [](int &x) { return (x%2!=0); }, 100);
    cout << "v1: " << v1 << endl;

}

/* Kjøring av programmet:
v1: 3 3 12 14 17 25 30
v2: 2 3 12 14 24
25 fins i v1 på indeks 5
Søker i en del av tabellen: 12 14 17
14 fins i v1 på indeks 3
Første på indeks 2
Finner to like på indeks 0
v1 inneholder 2 3-tall
Største verdi i v1 er 30
første element som er større enn 15 er: 17
v1: 3 3 12 14 17 25 30
v2: 2 3 12 14 24
de fem første elementene er ulike
de fire første elementene er like
v1: 3 3 12 14 17 25 30
v1: 100 100 12 14 100 100 30
*/
