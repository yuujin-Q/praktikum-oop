#include "User.h"
#include <iostream>
using namespace std;

int User::n_user = 0;

// ctor, parameter: nama pengguna
User::User(char* name) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->music_list = new char*[5000];
    this->num_of_favourite_music = 0;

    n_user++;
}

// cctor
User::User(const User& other) {
    this->name = new char[strlen(other.name)];
    strcpy(this->name, other.name);

    this->music_list = new char*[5000];
    this->num_of_favourite_music = other.num_of_favourite_music;
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }

    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User() {
    cout << "User " << this->name << " deleted" << endl;
    delete[] this->name;
    delete[] this->music_list;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* title) {
    this->music_list[this->num_of_favourite_music] = new char[strlen(title)];
    strcpy(this->music_list[this->num_of_favourite_music], title);
    this->num_of_favourite_music++;
}
void User::deleteFavouriteMusic(char* title) {
    if (this->num_of_favourite_music > 0) {
        for (int i = 0; i < this->num_of_favourite_music; i++) {
            if (!strcmp(this->music_list[i], title)) {
                if (i != this->num_of_favourite_music - 1) {
                    for (int j = i; j < this->num_of_favourite_music; j++) {
                        this->music_list[i] = new char[strlen(this->music_list[i + 1])];
                        strcpy(this->music_list[i], this->music_list[i + 1]);
                    }
                }
                this->num_of_favourite_music--;
                break;
            }
        }
    }
}

void User::setName(char* newName) {
    strcpy(this->name, newName);
}
char* User::getName() const {
    return this->name;
}
int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const {
    if (this->num_of_favourite_music > 0) {
        for (int i = 0; i < this->num_of_favourite_music; i++)
        {
            cout << i + 1 << ". " << this->music_list[i] << endl;
        }
        
    } else {
        cout << "No music in your favourite list" << endl;
    }
}

int User::getNumOfUser() {
    return n_user;
}