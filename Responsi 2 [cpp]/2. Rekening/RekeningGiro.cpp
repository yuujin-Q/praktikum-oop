#include "RekeningGiro.h"
/* ctor */
RekeningGiro::RekeningGiro(double saldo, double sukuBunga) : Rekening(saldo) {
    this->sukuBunga = (sukuBunga < 0) ? 0 : sukuBunga;
}
/* get/set */
void RekeningGiro::setSukuBunga(double sukuBunga) {
    this->sukuBunga = sukuBunga;
}
double RekeningGiro::getSukuBunga() const {
    return this->sukuBunga;
}
/* member */
double RekeningGiro::hitungBunga() {
    return this->getSukuBunga() * this->getSaldo();
}
