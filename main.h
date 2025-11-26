#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <type_traits>
#include <numeric>
#include "base.h"

using namespace std;

template <typename T>
class Studentas {
public:
    using paz_type = T;

private:
    T paz;
    int egzas;
    float rez;
    float mediana;

public:
    Studentas() : Zmogus(), paz(), egzas(0), rez(0), mediana(0) {}

    Studentas(const string& v, const string& p, const T& paz, int e) :
        Zmogus(v, p), paz(paz), egzas(e), rez(0), mediana(0) {}

    ~Studentas() = default;

    // ~Studentas() {
    //     vard.clear();
    //     pav.clear();
    //     paz.clear();
    //     egzas = 0;
    //     rez = 0;
    //     mediana = 0;
    // }

    Studentas(const Studentas& other)
        : Zmogus(other.getVard(), other.getPav()),
          paz(other.paz),
          egzas(other.egzas),
          rez(other.rez),
          mediana(other.mediana)
    {}

    Studentas& operator=(const Studentas& other)
    {   if (this == &other) return *this;

        setVard(other.getVard());
        setPav(other.getPav());

        paz = other.paz;
        egzas = other.egzas;
        rez = other.rez;
        mediana = other.mediana;

        return *this;
    }

    void info() const override {
        cout << getVard() << getPav() << endl;
    }

    T getPaz() const { return paz; }
    int getEgzas() const { return egzas; }
    float getRez() const { return rez; }
    float getMediana() const { return mediana; }

    void setPaz(const T& p) { paz = p; }
    void setEgzas(int e) { egzas = e; }
    void setRez(float r) { rez = r; }
    void setMediana(float m) { mediana = m; }

    friend ostream& operator<<(ostream& os, const Studentas<T>& s) {
        os << s.getVard() << " " << s.getPav() << " " << s.rez << " " << s.mediana;
        return os;

    friend istream& operator>>(istream& is, Studentas<T>& s) {
        is >> s.vard >> s.pav >> s.egzas;
        return is;
    }
};

template <typename T>
Studentas<T> ivesk();
template <typename T>
Studentas<T> iveskIsFailo(const string &line);
template <typename T>
float skaiciuotiMediana(const T &pazymiai);
template <typename T>
T skaitytiIsFailo(const string &failoPavadinimas);
template <typename T>
Studentas<T> generuokStudenta();
template <typename T>
void rikiuotiIrSukurtGrupe(const T &visiStudentai, T &vargsiukai, T &galvociai, const string &kriterijus);
template <typename T>
void rikiuotiIrSukurtGrupe_2(T &visiStudentai, T &vargsiukai, const string &kriterijus);
template <typename T>
void rikiuotiIrSukurtGrupe_3(T &visiStudentai, T &vargsiukai, const string &kriterijus);
template <typename T>
void spausdintiIFaila(const T &grupe, const string &failoVardas);
template <typename Container, typename Comparator>
void rikiuoti(Container &temp, Comparator comp);

string formatuoti(string s, int plotis);

string SkaiciaiSuKableliu(float value);



