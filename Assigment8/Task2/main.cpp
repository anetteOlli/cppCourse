#include <iostream>
using namespace std;

//Assigment 8, task 2, main.cpp

/*
OPPGAVETEKST:

Du skal lage en template-klasse for par. De to elementene som inngår i et par kan være av forskjellig type. Klassen skal tilby følgende:

En konstruktør som tar begge elementene som argumenter.
En operator for å legge sammen to par. Den skal lages ved elementvis summering, se eksemplet nedenfor.
En operator for å finne ut om et par er større enn et annet par. Her skal du sammenligne summen av elementene i hvert enkelt par, se eksemplet nedenfor.
Forutsett at det du måtte trenge av ytterligere versjoner av operatorene + og > eksisterer. Hvilke forutsetninger gjør du?

Klassetemplaten skal kunne brukes i følgende:
int main() {
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/

*/

template <typename Type1, typename Type2>
class Pair{
public:
    Type1 first;
    Type2 second;

    //constructor:
    Pair(Type1 first, Type2 second) : first(first), second(second){}

    Pair operator+(const Pair &other){
        //forutsetter at pair.first og other.first er av typer som kan summeres sammen
        Pair pair = *this;
        pair.first += other.first;
        pair.second += other.second;
        return  pair;
    }

    bool operator>(const Pair &other) const{
        //Forutsetninger: at innholdet i par.first og par.second kan summeres.
        //og at datatypen vi får fra summene kan sammenlignes med > operatoren
        auto pair1_sum = this->first + this->second;
        auto pair2_sum = other.first + other.second;
        return (pair1_sum > pair2_sum);
    }

    friend std::ostream &operator<<(std::ostream &os, const Pair &pair) {
        return os << "(" << pair.first << ", " << pair.second  << ")";
    }
};
int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;
}
