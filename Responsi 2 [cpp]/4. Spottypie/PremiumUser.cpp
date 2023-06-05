#include "PremiumUser.h"
#include <iostream>
using namespace std;

//ctor, active = true, parameter: nama pengguna
PremiumUser::PremiumUser(char* name) : User(name) {
    this->num_of_music_downloaded = 0;
    this->active = true;
}

// cctor
PremiumUser::PremiumUser(const PremiumUser& other) : User(other.name) {
    this->music_list = new char*[5000];
    this->num_of_favourite_music = other.num_of_favourite_music;
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    this->num_of_music_downloaded = other.num_of_music_downloaded;
    this->active = other.active;
} // implementasikan jika diperlukan, 
// jika tidak diperlukan, hapus cctor
// jika perlu diimplementasikan, print "Premium User Copied<endl>"

// dtor; implementasikan jika diperlukan
PremiumUser::~PremiumUser() {}

// jika tidak diperlukan, hapus dtor
// jika diperlukan
// selain implementasi, print juga "Premium user <nama user> deleted<endl>"
// Contoh:
// Premium user A deleted

// print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
// Contoh: 
// Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
//
// Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
void PremiumUser::downloadMusic(char* title) {
    if (active) {
        this->num_of_music_downloaded++;
        cout << "Music Downloaded: " << title << endl;
    } else {
        cout << "Activate premium account to download music" << endl;
    }
}
void PremiumUser::inactivatePremium() {
    this->active = false;
}
void PremiumUser::activatePremium() {
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return this->num_of_music_downloaded;
}

// mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const {
    return this->active;
}