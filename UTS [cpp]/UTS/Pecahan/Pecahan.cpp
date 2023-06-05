// Eugene Yap Jin Quan 13521074
#include "Pecahan.hpp"
#include <iostream>
using namespace std;

// ctor: set n = 0 dan d = 1
pecahan::pecahan() : n(0), d(1) {}

// ctor: set n = _n dan d = _d
pecahan::pecahan(int _n, int _d) : n(_n), d(_d) {}

pecahan::pecahan(const pecahan &P) {
    this->n = P.n;
    this->d = P.d;
} // cctor:

pecahan::~pecahan() {} // dtor

int pecahan::getPemb() {
    return this->n;
} // Menghasillkan pembilang n
int pecahan::getPeny() {
    return this->d;
} // Menghasilkan penyebut d

void pecahan::setPemb(int _n) {
    this->n = _n;
} // Mengubah nilai n menjadi _n
void pecahan::setPeny(int _d) {
    this->d = _d;
} // Mengubah nilai d menjadi _d

pecahan pecahan::operator+(const pecahan &P) {
    int n = this->getPemb() * P.d + P.n * this->getPeny();
    int d = this->getPeny() * P.d;
    return pecahan(n, d);
}
// Menambahkan pecahan dengan P
// Rumus = n1/d1 + n2/d2 = (n1*d2 + n2*d1)/d1*d2

pecahan pecahan::operator-(const pecahan &P) {
    int n = this->getPemb() * P.d - P.n * this->getPeny();
    int d = this->getPeny() * P.d;
    return pecahan(n, d);
}
// Menambahkan pecahan dengan P
// Rumus = n1/d1 - n2/d2 = (n1*d2 - n2*d1)/d1*d2

pecahan pecahan::operator*(int x) {
    int n = this->getPemb() * x;
    int d = this->getPeny() * x;
    return pecahan(n, d);
}
// Mengalikan pembilang P dengan x dan penyebut P dengan x
// Syarat: x > 0
// Rumus = n1/d1 = (n1*x)/(d1*x)

int gcd(int a, int b) {
    // a = q*b + r
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }   
}

bool pecahan::operator==(const pecahan &P) {
    // pecahan pp = *this - P;
    // return pp.getPemb() == 0;

    int gcd1 = gcd(this->n, this->d);
    int gcd2 = gcd(P.n, P.d);

    return (this->n / gcd1 == P.n / gcd2) && (this->d / gcd1 == P.d / gcd2);
}
// Mengecek apakah kedua pecahan memiliki nilai yang sama
// Hint: bandingkan dengan gcd, tidak boleh dibandingkan dengan RealP()!

float pecahan::RealP() {
    return float(this->getPemb()) / float(this->getPeny());
}
// Menghasilkan bentuk desimal dari pecahan

void pecahan::Print() {
    cout << this->getPemb() << '/' << this->getPeny();
}
// Mencetak pecahan dalam format: n/d (tanpa tambahan karakter apa pun
// di depan, tengah, atau belakang)