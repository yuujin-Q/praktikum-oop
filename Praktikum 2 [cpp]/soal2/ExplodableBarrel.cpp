// 13521074 Eugene Yap Jin Quan
#include "ExplodableBarrel.hpp"
 
// Default Constructor
// health dari ExplodableBarrel selalu 1 dan
// default radiusnya adalah 5
ExplodableBarrel::ExplodableBarrel() : Damageable(1), Explodable(), radius(5) {}

// Masukan: radius (integer positif) dan baseDamage (integer positif)
// health dari ExplodableBarrel selalu 1
ExplodableBarrel::ExplodableBarrel(int radius, int baseDamage) : Damageable(1), Explodable(baseDamage), radius(radius) {}

// Masukan: damage (integer positif) dan element (string)
//
// Berikut adalah urutan aksi yang dilakukan:
//
// Apabila barrel telah hancur, maka tidak akan terjadi
// apa-apa.
//
// Barrel menerima damage dan tidak menghiraukan element.
// Apabila barrel hancur setelah menerima damage, maka
// barrel akan meledak sebesar radius yang telah ditentukan.
void ExplodableBarrel::takeDamage(int damage, string element) {
    if (!this->Damageable::isDestroyed() && damage > 0) {
        this->Damageable::takeDamage(damage);
        if (this->Damageable::isDestroyed()) {
            this->Explodable::explode(this->radius);
        }
    }
}

