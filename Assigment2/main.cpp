#include <iostream>

using namespace std;

int find_sum(const int *table, int length){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += table[i];
    }
    return sum;
}

int main() {

    //OPPGAVE 1a)
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout <<"verdien til i: " << i << endl;
    cout << "adressen til i: " << &i << endl;
    cout << "verdien til p: " << p << endl;

    cout << "verdien til j: " << j << endl;
    cout << "adressen til j: " << &j << endl;
    cout << "verdien til q: " << q << endl;


    //OPPGAVE 1b)
    *p = 7;
    cout << "verdien til i: " <<i << ", verdien til p: " << *p <<endl;
    *q += 4;
    cout << "verdien til j: " << j << ", verdien til q: " << *p << endl;
    *q = *p +1;
    cout << "verdien til j: " << j << ", verdien til q: " << *q << endl;
    p = q;
    cout << "verdien til j: " << j << ", verdien til p: " << *p << endl;

    //OPPGAVE 4
    int a = 5;
    int &b = a; //int %b; fikk aldri initalisert b.
    int *c;
    c = &b;
    a = b + *c; //*a er ikke en pointer. b er et annet navn for a, så kan ikke bruke *b
    b = 2; // &b = 2: kan ikke endre adressa til b på denne måten.


    //OPPGAVE 5:
    double number;
    double *numberPointer = &number;
    double &referanseNumber = number;

    number = 3;
    referanseNumber = 7;
    *numberPointer = 6;


    //OPPGAVE 6:
    int length = 20;
    int table[20];
    for (int i = 0; i < 20; i++ ) {
        table[i] = i+1;
    }

    //tell over de første 10 tallene:
    int forste10 = find_sum(table, 10);
    cout << "de første 10 tallene: " << forste10 << endl;
    //tell over de neste 5 tallene:
    int neste5 = find_sum(&table[10], 5);
    cout << "de neste 5 tallene: " << neste5 << endl;
    //tell over de siste 5 tallene:
    int siste5 = find_sum(&table[15], 5);
    cout << "de siste 5 tallene: " << siste5 << endl;

    return 0;
}

