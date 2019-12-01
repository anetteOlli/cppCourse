#include <iostream>
#include <string>
using namespace std;


//Assigment 3, task4

int main() {

    //oppgave a: les inn 3 ord fra brukeren
    string word_temp = "";
    string word1 = "";
    string word2 = "";
    string word3 = "";

    int out_of_scope = -1;

    //using getline to prevent cin abuse:

    cout << "Skriv inn første ord:" << endl;

    getline(cin, word_temp);
    size_t position = word_temp.find(" ", 0);
    if (position != out_of_scope){
        word1 = word_temp.substr(0, position);
    }else {
        word1 = word_temp;
    }

    //resetting the position variable and word_temp
    position = 0;
    word_temp = "";
    cout << "Skriv inn andre ord:" << endl;
    getline(cin, word_temp);
    position = word_temp.find(" ", 0);
    if (position != out_of_scope){
        word2 = word_temp.substr(0, position);
    }else {
        word2 = word_temp;
    }

    //resetting the position variable and word_temp
    position = 0;
    word_temp = "";
    cout << "Skriv inn tredje ord:" << endl;
    getline(cin, word_temp);
    position = word_temp.find(" ", 0);
    if (position != out_of_scope){
        word3 = word_temp.substr(0, position);
    }else {
        word3 = word_temp;
    }

    //oppgave b) lag en streng der du skjøter sammen ordene med mellomrom og punktum på slutten
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "setningen ble: " << sentence << endl;

    //oppgave c) skriv ut lengden på hver enkelt ord og setningen som helhet:
    cout << "lengden på word1: " << word1.length() << ", lengden på word2: " << word2.length() << " og lengden på word3: " << word3.length() << endl;
    cout << "lengden på hele setningen: " << sentence.length() << endl;

    //oppgave d) lag en kopi av sentence. kall kopien sentence2.
    string sentence2(sentence);

    //oppgave e) bytt ut tegnene i position 10-12 med X i sentence2. Skriv ut sentence2 og sentence
    for (size_t i = 10; i < sentence2.length() && i <= 12; i++){
        sentence2[i] = 'X';
    }
    cout << endl;
    cout << "sentence2: " << sentence2 << endl;
    cout << "sentence: " << sentence << endl;

    //Oppgave f) Lagre de fem første tegnene i sentence i objektet sentence_start.
    // Skriv ut sentence og sentence_start. (Husk kontroll av gyldige posisjoner)

    //sjekk om strengen er lengre enn 5 karakterer lang: kopier 5 første
    //ellers kopier hele strengen...
    string sentence_start = "";
    if(sentence.length() > 5){
        sentence_start.append(sentence, 0, 5);
    }else{
        sentence_start += sentence;
    }
    cout << "sentence_start: " << sentence_start << endl;


    //Oppgave g) Finn ut om sentence inneholder ordet "hallo". Skriv ut resultatet.
    size_t start = sentence.find("hallo");
    if(start != out_of_scope){
        cout << "hallo finnes i sentence" << endl;
    } else {
        cout << "hallo finnes ikke i sentence" << endl;
    }

    //oppgave h)Finn alle forekomster i sentence av strengen "er". Skriv ut resultatet.
    size_t found = sentence.find("er");
    while (found != out_of_scope) {
        cout << " er har blitt funnet på posisjon: " << found << endl;
        found = sentence.find("er", found+1);
    }

    return 0;
}
