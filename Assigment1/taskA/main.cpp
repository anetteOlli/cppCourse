#include <iostream>
using namespace std;

/*
Oppgavebeskrivelse:
Les inn temperaturene (datatype double) fra brukeren. Bruk ikke tabeller, og lag heller ikke egne funksjoner. Brukergrensesnittet kan se slik ut:

Du skal skrive inn 5 temperaturer.
Temperatur nr 1: 10
Temperatur nr 2: 14
Temperatur nr 3: 20
Temperatur nr 4: 25
Temperatur nr 5: 8
Antall under 10 er 1
Antall mellom 10 og 20 er 3
Antall over 20 er 1
 */

int main() {
    cout << "Hello, World!" << std::endl;


    const int length = 5;
    double number1 = 0;
    double number2 = 0;
    double number3 = 0;
    double number4 = 0;
    double number5 = 0;

    //Since arrays weren't allowed: no for-loops is being used
    cout << "Du skal skrive inn 5 temperaturer." << endl;
    cout << "Temperatur nr 1:" ;
    cin >> number1;
    cout << "Temperatur nr 2:";
    cin >> number2;
    cout << "Temperatur nr 3:";
    cin >> number3;
    cout << "Temperatur nr 4:";
    cin >> number4;
    cout << "Temperatur nr 5:";
    cin >> number5;


    int lessThan10 = 0;
    int between = 0;
    int above20 = 0;

    if (number1 < 10 ){
        lessThan10++;
    }else if (number1 > 20 ){
        above20++;
    }else {
        between++;
    }

    if (number2 < 10 ){
        lessThan10++;
    }else if (number2 > 20 ){
        above20++;
    }else {
        between++;
    }

    if (number3 < 10 ){
        lessThan10++;
    }else if (number3 > 20 ){
        above20++;
    }else {
        between++;
    }

    if (number4 < 10 ){
        lessThan10++;
    }else if (number4 > 20 ){
        above20++;
    }else {
        between++;
    }


    if (number5 < 10 ){
        lessThan10++;
    }else if (number5 > 20 ){
        above20++;
    }else {
        between++;
    }

    cout << "Antall under 10 er " << lessThan10 << endl;
    cout << "Antall mellom 10 og 20 er " << between << endl;
    cout << "Antall over 20 er " << above20 << endl;

    return 0;
}