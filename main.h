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
class Studentas : public Zmogus {
public:
    using paz_type = T;

private:
    T paz;
    int egzas;
    float rez;
    float mediana;

public:
    Studentas() : paz(), egzas(0), rez(0), mediana(0) {}

    Studentas(const string& v, const string& p, const T& paz, int e)
        : Zmogus{v, p}, paz(paz), egzas(e), rez(0), mediana(0) {}

    ~Studentas() {
        paz.clear();
        egzas = 0;
        rez = 0;
        mediana = 0;
    }

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
        cout << getVard() << " " << getPav() << " ";

        for (int x : getPaz())
            cout << x << " ";

        cout << endl;
    }

    const T& getPaz() const { return paz; }
    int getEgzas() const { return egzas; }
    float getRez() const { return rez; }
    float getMediana() const { return mediana; }

    void setPaz(const T& p) { paz = p; }
    void setEgzas(int e) { egzas = e; }
    void setRez(float r) { rez = r; }
    void setMediana(float m) { mediana = m; }

    friend ostream& operator<<(ostream& os, const Studentas<T>& s) {
        os << s.getVard() << " " << s.getPav() << " | ";
        for (const auto& pazymys : s.getPaz()) {
            os << " " << pazymys;
        }
        os << " | " << s.getEgzas() << " | " << s.getRez() << " " << s.getMediana();
        return os;
    }

    friend istream& operator>>(istream& is, Studentas<T>& s)
    {
        string vard, pav;
        if (!(is >> vard >> pav)) return is;

        s.setVard(vard);
        s.setPav(pav);

        T pazymiai;
        int x;

        while (is >> x) {
            pazymiai.push_back(x);
    }

        is.clear();
    if (pazymiai.empty()) {
            s.setPaz(T{});
            s.setEgzas(0);
            return is;
        }
        auto it = std::prev(pazymiai.end());
        int egzas = *it;
        pazymiai.erase(it);

        s.setPaz(pazymiai);
        s.setEgzas(egzas);

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
