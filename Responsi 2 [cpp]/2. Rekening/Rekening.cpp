#include "Rekening.h"
/* ctor */
Rekening::Rekening(double saldo) {
    this->saldo = (saldo < 0) ? 0 : saldo;
}
/* get/set */
void Rekening::setSaldo(double saldo) {
    this->saldo = saldo;
}
double Rekening::getSaldo() const {
    return this->saldo;
}
/* member function */
void Rekening::simpanUang(double nominal) {
    this->saldo += nominal;
}
bool Rekening::tarikUang(double nominal) {
    if (nominal > this->saldo) {
        return false;
    } else {
        this->saldo -= nominal;
        return true;
    }
}