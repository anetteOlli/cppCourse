#include <iostream>
using namespace std;

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