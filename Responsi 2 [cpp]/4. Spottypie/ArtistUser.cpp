#include "ArtistUser.h"
#include <iostream>
using namespace std;

int ArtistUser::num_of_artist = 0;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* name) : User(name) {
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char*[5000];
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& other) : User(other) {
    this->num_of_favourite_music = other.num_of_favourite_music;
    this->music_list = new char *[5000];
    for (int i = 0; i < other.num_of_favourite_music; i++)
    {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    this->num_of_music_uploaded = other.num_of_music_uploaded;
    this->uploaded_music_list = new char *[5000];
    for (int i = 0; i < other.num_of_music_uploaded; i++)
    {
        this->uploaded_music_list[i] = new char[strlen(other.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], other.uploaded_music_list[i]);
    }
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser() {
    delete[] this->uploaded_music_list;
    cout << "Artist user " << this->name << " deleted\n";
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* title) {
    this->uploaded_music_list[this->num_of_music_uploaded] = new char[strlen(title)];
    strcpy(this->uploaded_music_list[this->num_of_music_uploaded], title);
    this->num_of_music_uploaded++;
}
void ArtistUser::deleteUploadedMusic(char* title) {
    if (this->num_of_music_uploaded > 0) {
        for (int i = 0; i < this->num_of_music_uploaded; i++) {
            if (!strcmp(this->uploaded_music_list[i], title)) {
                if (i != this->num_of_music_uploaded - 1) {
                    for (int j = i; j < this->num_of_music_uploaded; j++) {
                        this->uploaded_music_list[i] = new char[strlen(this->uploaded_music_list[i + 1])];
                        strcpy(this->uploaded_music_list[i], this->uploaded_music_list[i + 1]);
                    }
                }
                this->num_of_music_uploaded--;
                break;
            }
        }
    }
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const {
    if (this->num_of_music_uploaded > 0) {
        for (int i = 0; i < this->num_of_music_uploaded; i++) {
            cout << (i + 1) << ". " << this->uploaded_music_list[i] << endl;
        }
    } else {
        cout << "No music uploaded" << endl;
    }
}
int ArtistUser::getNumOfMusicUploaded() const {
    return this->num_of_music_uploaded;
}
int ArtistUser::getNumOfArtist() {
    return num_of_artist;
}