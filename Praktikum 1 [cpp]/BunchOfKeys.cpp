/**
 * Identitas: 13521074 - Eugene Yap Jin Quan
 * Tanggal : 2023/02/09
 * Topik : Praktikum 1
 */
#include "BunchOfKeys.hpp"
using namespace std;

BunchOfKeys::BunchOfKeys() : n_keys(0){
}

void BunchOfKeys::add() {
	this->n_keys++;
}

void BunchOfKeys::shake() {
	if (this->n_keys > 1) {
		for (int i = 0; i < this->n_keys; i++) {
			cout << "krincing" << endl;
		}
	} else {
		cout << "Tidak terjadi apa-apa" << endl;
	}
}
