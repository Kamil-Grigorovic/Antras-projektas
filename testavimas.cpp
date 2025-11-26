#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "main.h"

using namespace std;

template <typename T>
void test_studentas(const std::string& konteinerio_pavadinimas) {
    cout << "|.. TESTUOJAME Studentas<" << konteinerio_pavadinimas << "> ..|\n";

    // Testuojame operator>>
    std::stringstream ss("Jonas Jonaitis 10 9 8 7 6 5");
    Studentas<T> s1;
    ss >> s1;

    cout << "Vardas:  " << s1.getVard() << endl;
    cout << "Pavarde: " << s1.getPav() << endl;

    cout << "Egzaminas (turi buti 5): " << s1.getEgzas() << endl;

    cout << "ND pazymiai (turi buti 10 9 8 7 6): ";
    for (int x : s1.getPaz()) cout << x << " ";
    cout << endl;

    // Tikriname kopijavimą
    Studentas<T> s2 = s1;
    cout << "Copy constructor testas (vardas): " << s2.getVard() << endl;

    Studentas<T> s3;
    s3 = s1;
    cout << "Copy assignment testas (pavarde): " << s3.getPav() << endl;

    // Tikriname medianą
    float med = skaiciuotiMediana(s1.getPaz());
    cout << "Mediana (turi buti 8): " << med << endl;

    // Galutinio balo skaičiavimas
    int sum = 0;
    for (int x : s1.getPaz()) sum += x;
    float vid = (float)sum / s1.getPaz().size();
    float tikras_galutinis = 0.4f * vid + 0.6f * s1.getEgzas();

    cout << "Tikras galutinis balas (turi buti): " << tikras_galutinis << endl;

    // Tikriname operator<<
    cout << "operator<< testas: ";
    cout << s1 << endl;

    cout << "|.. Testas baigtas ..|\n" << endl;
}

int main() {

    cout << "=== BENDRINIAI TESTAI ===\n";

    // Testas su vector<int>
    test_studentas<std::vector<int>>("vector<int>");
    // Testas su list<int>
    test_studentas<std::list<int>>("list<int>");

    cout << "\n=== VISI TESTAI BAIGTI ===\n";
    return 0;
}
