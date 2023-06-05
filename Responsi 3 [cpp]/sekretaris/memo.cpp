// Eugene Yap Jin Quan 13521074
#include "memo.h"

/* 
    Membuat objek Memo dengan 'pesan' dan 'untuk' kosong
*/
Memo::Memo() : pesan(""), untuk("") {}

/* 
    Membuat objek Memo dengan isi sesuai yang diberikan.

    Jika panjang pesan melebihi panjang maksimum, maka
    metode ini melemparkan PesanKepanjanganException.
*/
Memo::Memo(string pesan, string untuk) {
    if (pesan.length() > PESAN_MAX) {
        PesanKepanjanganException pesanExc;
        throw pesanExc;
    } 
    this->pesan = pesan;
    this->untuk = untuk;
}

/* 
    Menyalin nilai pesan dan untuk ke objek lain
*/
Memo& Memo::operator=(Memo& obj) {
    this->pesan = obj.getPesan();
    this->untuk = obj.getUntuk();
    return *this;
}

/*
    Mendapatkan nilai pesan
*/
string Memo::getPesan() {
    return this->pesan;
}

/*
    Mendapatkan nilai untuk
*/
string Memo::getUntuk() {
    return this->untuk;
}