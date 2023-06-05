/**
 * Identitas: 13521074 - Eugene Yap Jin Quan
 * Tanggal : 2023/02/09
 * Topik : Praktikum 1
 */
#include "Kompleks.h"
#include <iostream>
using namespace std;

int Kompleks::n_kompleks = 0;

// ctor tanpa parameter
// inisialisasi seluruh koefisien dengan nilai 0
Kompleks::Kompleks() : real(0), imaginer(0) {
	n_kompleks++;
}

// ctor dengan parameter
Kompleks::Kompleks(int real, int imaginer) {
	this->real = real;
	this->imaginer = imaginer;
	n_kompleks++;
}

//mengembalikan bagian riil
int Kompleks::GetReal() const {
	return this->real;
}

// mengembalikan bagian imaginer
int Kompleks::GetImaginer() const {
	return this->imaginer;
}

// mengisi bagian riil
void Kompleks::SetReal(int r) {
	this->real = r;
}

// mengisi bagian imaginer
void Kompleks::SetImaginer(int i) {
	this->imaginer = i;
}

// operator overloading

// operator+ untuk melakukan penjumlahan dengan rumus berikut
// (a + bi) + (c + di) = (a+c) + (b+d)i
Kompleks operator+ (const Kompleks& A, const Kompleks& B) {
	Kompleks C(A.GetReal() + B.GetReal(), A.GetImaginer() + B.GetImaginer());
	return C;
}

// operator- untuk melakukan pengurangan dengan rumus berikut
// (a + bi) − (c + di) = (a−c) + (b−d)i
Kompleks operator- (const Kompleks& A, const Kompleks& B) {
	Kompleks C(A.GetReal() - B.GetReal(), A.GetImaginer() - B.GetImaginer());
	return C;
}

// operator* untuk melakukan perkalian dengan rumus berikut
// (a + bi)(c + di) = ac + bci + adi + bd i^2 = (ac−bd) + (bc+ad)i
Kompleks operator* (const Kompleks& A, const Kompleks& B) {
	Kompleks C(	A.GetReal() * B.GetReal() - A.GetImaginer() * B.GetImaginer(), 
				A.GetImaginer() * B.GetReal() + A.GetReal() * B.GetImaginer());
	return C;
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta
// (a + bi)(c) = (ac) + (bc)i
Kompleks operator* (const Kompleks& A, const int k) {
	Kompleks C(k * A.GetReal(), k * A.GetImaginer());
	return C;
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta (sifat komutatif)
Kompleks operator* (const int k, const Kompleks& A) {
	Kompleks C(k * A.GetReal(), k * A.GetImaginer());
	return C;
}

// mengembalikan jumlah instance yang pernah dibuat
int Kompleks::CountKompleksInstance() {
	return n_kompleks;
}

// mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
// contoh:
// 3+5i
// 0+0i
// -5-4i
void Kompleks::Print() {
	cout << this->real;
	if (this->imaginer >= 0) {
		cout << '+';
	}
	cout << this->imaginer << 'i';
	cout << endl;
}

