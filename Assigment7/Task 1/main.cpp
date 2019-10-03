#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

//Definerer - operator overloading, slik at vi kan få ut "5 – fraction1"
Fraction operator-(const int i, const Fraction &fraction) {
  Fraction integer_fraction(i, 1);
  return integer_fraction - fraction;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

  print("b -3=", b - 3);
  print("3-a=", 3 - a);
}

/*oppgave b): Teori: Forklar hvordan "5 - 3 - fraction1 - 7 - fraction2" blir tolket. Hvilke versjoner av operatoren - blir brukt?

i 5 -3 biten tar den i bruk den innebygde operatoren, resultatet blir 2
i 2 - fraction1 tar den i bruk den globale operatoren som er lagd for å tolke integer substrahert fraksjon1
i fraction1 -7, tar den i bruk Fractions medlems operator som håndterer fraksjoner substrahert integers.
i fraction - fraction2, tar den i bruk Fractions medlemsoperator som håndterer fraksjoner substrahert fraksjoner.


*/