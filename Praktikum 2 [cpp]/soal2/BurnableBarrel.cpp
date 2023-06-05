// 13521074 Eugene Yap Jin Quan
#include "BurnableBarrel.hpp"

// Default Constructor
BurnableBarrel::BurnableBarrel() : Damageable(), Burnable() {}

// Masukan: health (integer positif)
BurnableBarrel::BurnableBarrel(int health) : Damageable(health), Burnable() {}

// Masukan: damage (integer positif) dan element (string)
//
// Berikut adalah urutan aksi yang dilakukan:
//
// Apabila barrel telah hancur, maka tidak akan terjadi
// apa-apa.
//
// Apabila barrel menerima damage element berupa "fire",
// maka akan mengaktifkan status burned. Apabila barrel
// menerima damage element berupa "water", maka status
// burned akan dinonaktifkan.
//
// Setelah update status burned, Jika barrel dalam kondisi
// burned, maka damagenya akan dikalikan dengan konstanta
// multiplier. Jika tidak, maka damagenya tidak berubah.
void BurnableBarrel::takeDamage(int damage, string element) {
    if (!this->Damageable::isDestroyed() && damage > 0) {
        if (element == "fire") {
            this->Burnable::burn();
        } else if (element == "water") {
            this->Burnable::watered();
        }

        if (this->Burnable::isBurned()) {
            this->Damageable::takeDamage(damage * Burnable::multiplier);
        } else {
            this->Damageable::takeDamage(damage);
        }
    }
}
