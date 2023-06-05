/*
Kelas SpacingGuildShip merupakan pesawat luar angkasa dengan kapasitas penumpang maxPassengerCap dan navigator bernama Guild Navigator sebanyak guildNavigatorCount. Kelas SpacingGuildShip menyimpan berapa banyak pesawat yang telah diproduksi (producedShips) dan catatan total jarak yang ditempuh oleh semua pesawat (totalGuildTravel). Pesawat menampung penumpang sebanyak passengerCount dan memiliki nomor seri yang unik serialNum.

SerialNum didapat dari jumlah pesawat yang diproduksi (producedShips + 1) Implementasi kelas SpacingGuildShip dalam bentuk SpacingGuildShip.cpp dari definisinya di SpacingGuildShip.hpp
*/

#include "SpacingGuildShip.hpp"

using namespace std;

/*
    const int maxPassengerCap;		// Kapasitas maksimal penumpang pesawat
	int passengerCount;				// Jumlah penumpang	
	const int guildNavigatorCount;	// Jumlah Guild Navigator dalam pesawat
	int operatingGuildNavigator;	/* Jumlah Guild Navigator yang operasional
									   (default: semua operasional)	
	const int serialNum;			// Nomor produksi pesawat sesuai urutan produksi
	int spiceStock;					// Stok spice pesawat
	static float totalGuildTravel;	// Total jarak yang ditempuh oleh setiap SpacingGuildShip
	static int producedShips;		// Jumlah pesawat yang telah diproduksi
*/

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(SpacingGuildShip::producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = 50;
    SpacingGuildShip::producedShips++;
}
	/* Ctor default: jumlah penumpang adalah 0, jumlah Guild Navigator adalah 3,
	 * Kapasitas pesawat adalah 50 orang, dan stok spice 50*/

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(SpacingGuildShip::producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    SpacingGuildShip::producedShips++;
}
	/* Ctor jika diketahui jumlah Guild Navigator, kapasitas maksimal pesawat, 
	 * dan stok spice. Jumlah penumpang 0 */

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& other): maxPassengerCap(other.maxPassengerCap), guildNavigatorCount(other.guildNavigatorCount), serialNum(SpacingGuildShip::producedShips + 1) {
    this->passengerCount = other.passengerCount;
    this->operatingGuildNavigator = other.guildNavigatorCount;
    this->spiceStock = other.spiceStock;
    SpacingGuildShip::producedShips++;
}
	/* Cctor SpacingGuildShip */

SpacingGuildShip::~SpacingGuildShip() {
}
	/* Dtor SpacingGuildShip */

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}
/* Mengembalikan serial number dari pesawat */

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}
/* Mengembalikan jumlah penumpang pesawat */


void SpacingGuildShip::travel(float distance) {
    if (this->operatingGuildNavigator != 0) {
        SpacingGuildShip::totalGuildTravel += distance / (E * E * this->operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}
/* Pesawat bergerak sebesar distance, sehingga 
    * totalGuildTravel bertambah sebesar:
    *
    * distance / (E^2 * operatingGuildNavigator).
    * 
    * Catatan: 
    * 1. Apabila tidak ada Guild Navigator yang operasional, 
    *    maka totalGuildTravel tidak bertambah;
    * 2. Apabila ada Guild Navigator yang operasional, 
    *    maka jumlah Guild Navigator operasional berkurang 1 */

void SpacingGuildShip::boarding(int addedPassengers) {
    if (this->passengerCount + addedPassengers > this->maxPassengerCap) {
        this->passengerCount = this->maxPassengerCap;
    } else {
        this->passengerCount += addedPassengers;
    }
}
/* Penumpang naik ke pesawat sebesar addedPassenger. 
* Jika pesawat tidak muat, penumpang pesawat menjadi penuh */

void SpacingGuildShip::dropOff(int droppedPassengers) {
    if (droppedPassengers > this->passengerCount) {
        this->passengerCount = 0;
    } else {
        this->passengerCount -= droppedPassengers;
    }
}
/* Penumpang turun dari pesawat sebesar droppedPassenger. 
* Jika jumlah penumpang kurang, kosongkan pesawat */

void SpacingGuildShip::refreshNavigator(int n) {
    if (n > this->operatingGuildNavigator) {
        n = this->operatingGuildNavigator;
    }

    for (int i = 0; i < n; i++) {
        if (this->spiceStock - GUILD_NAVIGATOR_SPICE_DOSE >= 0) {
            this->spiceStock -= GUILD_NAVIGATOR_SPICE_DOSE;
        } else {
            break;
        }
    }
    
}
/* Menambah n Guild Navigator operasional yang menghabiskan
* n * GUILD_NAVIGATOR_SPICE_DOSE spice dari stok.
* 
* Catatan:
* 1. Maksimum merefresh seluruh Guild Navigator yang ada di pesawat 
* 2. Apabila stok kurang, maka merefresh n maksimum yang dapat di refresh
*    dari stok spice yang ada */

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    this->spiceStock += addedSpice;
}
/* Menambah stok spice sebesar addedSpice */