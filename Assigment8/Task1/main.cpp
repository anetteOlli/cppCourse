#include <iostream>
#include <cmath>

//Assigment 8, task 1, main.cpp

/*
OPPGAVETEKST:
Lag en funksjonstemplate som finner ut om to verdier er like (for eksempel: template <typename Type> bool equal(Type a, Type b) {...}). Du kan anta at sammenlikningsoperatorene er implementert for den aktuelle datatypen.

Lag en spesialutgave for double (for eksempel: bool equal(double a, double b) {...}). Denne funksjonen skal kunne brukes for beregnede desimaltallsverdier. Anta at to slike verdier betraktes som like dersom forskjellen mellom dem er mindre enn for eksempel 0.00001.

Lag et lite program som prøver både template-utgaven og spesialutgaven. Sjekk at riktig utgave blir brukt ved å legge inn utskrift-setninger inni funksjonene. Du vil kanskje trenge å skrive ut double med mer enn 6 desimaler, bruk i tilfelle manipulatoren setprecision().
*/

template <typename Type>
   bool equal(Type a, Type b){
    return a == b;
}


bool equal(double a, double b) {
    return (std::abs(a -b) <=0.00001);
}

int main() {
    int a = 0;
    int b = 0;
    int c = 1;
    double d = 0.03;
    double e = 0.03000000001;
    double f = 0.0301;
    std::cout << "a==b: " << equal(a, b) << std::endl;
    std::cout << "a==c: " << equal(a, c) << std::endl;
    std::cout << "d==e: " << equal(d, e) << std::endl;
    std::cout << "d==f: " << equal(d, f) << std::endl;
    return 0;
}
