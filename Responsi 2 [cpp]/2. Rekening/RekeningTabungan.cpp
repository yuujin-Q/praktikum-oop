#include "RekeningTabungan.h"
/* ctor */
RekeningTabungan::RekeningTabungan(double saldo, double biayaTransaksi) : Rekening(saldo) {
    this->biayaTransaksi = (biayaTransaksi < 0) ? 0 : biayaTransaksi;
}
/* get/set */
void RekeningTabungan::setBiayaTransaksi(double biayaTransaksi) {
    this->biayaTransaksi = biayaTransaksi;
}
double RekeningTabungan::getBiayaTransaksi() const {
    return this->biayaTransaksi;
}
/* member function */
void RekeningTabungan::simpanUang(double nominal) {
    this->Rekening::simpanUang(nominal);
    this->setSaldo(this->getSaldo() - this->getBiayaTransaksi());
}
bool RekeningTabungan::tarikUang(double nominal) {
    bool success = this->Rekening::tarikUang(nominal);
    if (success) {
        this->setSaldo(this->getSaldo() - this->getBiayaTransaksi());
    }
    return success;
}