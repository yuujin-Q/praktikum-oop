#include <iostream>
using namespace std;

class Hewan {
    protected:
        string nama;
    public:
        Hewan() {}
        Hewan(string nama) {
            this->nama = nama;
        }
        ~Hewan() {
            cout << "Hewan mati " << this->nama << endl;
        }
        virtual void print() {
            cout << "Hewan ini namanya " << this->nama << endl;
        }
};

class Anjing : public Hewan {
    public:
        Anjing() {}
        Anjing(string nama) {
            this->nama = nama;
        }
        ~Anjing() {
            cout << "Anjing mati " << this->nama << endl;
            // Hewan::~Hewan();
        }
        virtual void print() {
            cout << "Anjing ini namanya " << this->nama << endl;
        }
};

class Kucing : public Hewan {
    public:
        Kucing() {}
        Kucing(string nama) {
            this->nama = nama;
        }
        virtual ~Kucing() {
            cout << "Kucing mati " << this->nama << endl;
            // Hewan::~Hewan();
        }
        // void print() {
        //     cout << "Kucing ini namanya " << this->nama << endl;
        // }
};

class AnjingBulldog : public Anjing {
    protected:
        string pemilik;
    public:
        AnjingBulldog() {}
        AnjingBulldog(string nama, string pemilik) {
            this->nama = nama;
            this->pemilik = pemilik;
        }
        ~AnjingBulldog() {
            cout << "Anjing bulldog mati " << this->nama << endl;
            // Anjing::~Anjing();
        }
        void print() {
            cout << "Anjing bulldog ini namanya " << this->nama << ". Pemiliknya adalah " << this->pemilik << endl;
        }
};

class KucingAnggora : public Kucing {
    protected:
        string pemilik;
    public:
        KucingAnggora() {}
        KucingAnggora(string nama, string pemilik) {
            this->nama = nama;
            this->pemilik = pemilik;
        }
        ~KucingAnggora() {
            cout << "Kucing anggora mati " << this->nama << endl;
            // Kucing::~Kucing();
        }
        void print() {
            cout << "Kucing anggora ini namanya " << this->nama << ". Pemiliknya adalah " << this->pemilik << endl;
        }
};
