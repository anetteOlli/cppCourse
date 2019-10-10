#include <iostream>
#include <vector>
#include "set.hpp"



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
