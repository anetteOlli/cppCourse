#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Assigment 4, taskA, main.cpp

OPPGAVETEKST:
Lag et lite program:

Opprett en vektor av double. Legg inn fem tall (behøver ikke leses inn.)

Prøv ut medlemsfunksjonene front() og back(). De returnerer hver et element, og de har ingen argumenter.

Bruk emplace() til å sette inn et tall etter det første elementet. Skriv ut resultatet av front() etterpå.

Prøv ut STL-algoritmen find(). Den tar tre argumenter: start, slutt og søkeverdi. De to første er iteratorer til søkeintervallet. Funksjonen returnerer en iterator til den funne verdien, hvis den finnes. Hvis den ikke finnes, er returverdien lik end()-iteratoren. Lag et if-uttrykk som sjekker om resultatet av find() er vellykket eller ikke, og dersom resultatet var vellykket, skriv ut den funne verdien.
*/

int main() {

    vector<int> numbers = {3, 8, 9, 4, 6};

    int first_number = numbers.front();
    int last_number = numbers.back();

    cout << "first_number: " << first_number << endl;
    cout << "last_number: " << last_number << endl;
    numbers.emplace_back(30);

    int now_first = numbers.front();

    cout << "first number after emplace: " << now_first << endl;

    int start_search = 0;
    int end_search = 6;
    int search_for = 8;

    auto p = find(numbers.begin(), numbers.end(), search_for);
    if (p != end(numbers)){
        cout << "found the number" <<  p.base() <<endl;
    }else {
        cout << "could not find the number" << endl;
    }

    return 0;
}
