#include <iostream>
#include <vector>
#include "set.hpp"

//Assigment 7, task 2, main.cpp

/*
Du skal lage en klasse med en heltallstabell (std::vector) som datamedlem. Den skal inneholde forskjellige tall. Tallene skal ikke være sortert på noen bestemt måte. Vi sier at vi har en mengde, og vi kaller klassen Set.

Du skal lage medlemsfunksjoner for operasjonene nedenfor. Medlemsfunksjonene skal enten være konstruktører eller operatorer.

Implementer følgende operasjoner:

å lage en ny, tom mengde
å finne unionen av to mengder. Funksjonen skal altså lage en ny mengde som inneholder alle elementene som er i hver enkelt av de to mengdene. Men husk at dersom et element er i begge mengdene, skal det likevel forekomme bare en gang i resultatmengden. Eksempel: Unionen av {1, 4, 3} og {4, 7} er lik {1, 4, 3, 7}.
å legge et nytt tall inn i en mengde. Dersom tallet fins fra før, skal det ikke skje noe.
å sette en mengde lik en annen mengde
å skrive ut en mengde
Lag et lite program (main.cpp) slik at du får prøvd ut det du har laget.


*/


//lager metode slik at vi kan skrive ut innholdet
std::ostream &operator<<(std::ostream &stream, const Set &set) {
    stream << "{ ";
    for (unsigned i = 0; i < set.set_vector.size(); i++) {
        stream << set.set_vector.at(i) << ", ";
    }
    stream << "}";
    return stream;
}

int main() {
    std::vector<int> fire_100(4, 100);
    Set a(fire_100);
    a.set_new_element(88);
    Set b;
    b.set_new_element(32);
    b.set_new_element(100);
    Set c;
    c.set_new_element(45);
    c.set_new_element(45);
    std::cout<< "a: " << a << std::endl;
    std::cout<< "b: " << b << std::endl;
    std::cout<< "c: " << c << std::endl;

    std::cout << "a og b union: " << b.find_of_union_set(a) << std::endl;

    a.replace_set(c);
    std::cout << "setter a til å være lik c: " << a << std::endl;

}
