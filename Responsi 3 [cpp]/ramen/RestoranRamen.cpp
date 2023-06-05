// Eugene Yap Jin Quan 13521074
#include "RestoranRamen.hpp"
#include <iostream>
using namespace std;

// Menambah jumlah order yang dipesan oleh meja n, dengan harga p
// Jika meja sudah diisi maka akan menambah total yang telah dipesan
void RestoranRamen::tambahOrder(int n, int p) {
    map<int,int>::iterator itr = this->daftarMeja.find(n);
    if (itr == this->daftarMeja.end()) {
        this->daftarMeja.insert(pair<int,int> (n, p));
    } else {
        itr->second += p;
    }
}

// Mengembalikan total harga pesanan pada meja n, menghapus entri untuk meja tersebut
int RestoranRamen::tutupOrder(int n) {
    int price = this->cekTotal(n);
    this->daftarMeja.erase(n);
    return price;
}

// Mengembalikan total harga pesanan pada meja n
int RestoranRamen::cekTotal(int n) {
    map<int,int>::iterator itr = this->daftarMeja.find(n);
    if (itr != this->daftarMeja.end()) {
        return itr->second;
    } else {
        return 0;
    }
}

// Mengembalikan jumlah meja yang terisi saat itu
// Restoran mungkin kosong
int RestoranRamen::totalMeja() {
    return this->daftarMeja.size();
}

// Mencetak semua meja yang terisi pada restoran diakhiri dengan new line
// Contoh : 
/*
    Meja 1 = 5000
    Meja 2 = 3000
    Meja 4 = 10000
*/
// Jika restoran kosong akan mencetak "Restoran kosong" diakhiri new line
void RestoranRamen::cetakMeja() {
    if (this->totalMeja() == 0) {
        cout << "Restoran kosong" << endl;
    } else {
        map<int,int>::iterator itr;
        for (itr = this->daftarMeja.begin(); itr != this->daftarMeja.end(); itr++) {
            cout << "Meja " << itr->first << " = " << itr->second << endl;
        }
    }
}