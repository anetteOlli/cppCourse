#include <iostream>
#include <cmath>

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