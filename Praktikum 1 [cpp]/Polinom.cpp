/**
 * Identitas: 13521074 - Eugene Yap Jin Quan
 * Topik : Latihan Praktikum 1
 */

#include "Polinom.hpp"
#include <iostream>
#include <math.h>
using namespace std;

Polinom::Polinom() : derajat(0) {
    this->koef = new int[1];
    this->koef[0] = 0;
}

Polinom::Polinom(int order) : derajat(order) {
    this->koef = new int[order+1];
    for (int i = 0; i <= this->derajat; i++) {
        this->koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& other) {
    this->derajat = other.derajat;
    this->koef = new int[this->derajat];
    for (int i = 0; i <= this->derajat; i++) {
        this->koef[i] = other.koef[i];
    }
}

Polinom::~Polinom() {
    delete[] this->koef;
}

Polinom& Polinom::operator=(const Polinom& other) {
    this->derajat = other.derajat;
    delete[] this->koef;
    this->koef = new int[other.derajat];
    for (int i = 0; i <= other.derajat; i++) {
        this->koef[i] = other.koef[i];
    }
}

int Polinom::getKoefAt(int idx) const {
    return this->koef[idx];
}

int Polinom::getDerajat() const {
    return this->derajat;
}

void Polinom::setKoefAt(int idx, int val) {
    this->koef[idx] = val;
}

void Polinom::setDerajat(int ndeg) {
    this->derajat = ndeg;
}

void Polinom::input() {
    for (int i = 0; i <= this->derajat; i++) {
        cin >> this->koef[i];
    }
}

void Polinom::printKoef() {
    for (int i = 0; i <= this->derajat; i++) {
        cout << this->koef[i] << endl;
    }
}

int Polinom::substitute(int x) {
    int result = 0;
    for (int i = 0; i <= this->derajat; i++) {
        result += this->koef[i] * pow(x, i);
    }
    return result;
}

void Polinom::print() {
    int count = 0;

    for (int i = 0; i <= this->derajat; i++) {
        int currKoef = this->koef[i];
        if (currKoef != 0) {
            if (count > 0 && currKoef > 0) {
                cout << '+';
            }

            cout << currKoef;

            if (i > 0) {
                cout << "x^" << i;
            }

            count++;
        }
    }    

    if (count == 0) {
        cout << 0;
    }
    cout << endl;
}