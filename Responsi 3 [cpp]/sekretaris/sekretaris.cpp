// Eugene Yap Jin Quan 13521074
#include "sekretaris.h"
#include <iostream>
using namespace std;

/*
    Membuat objek Sekretaris dengan nilai kertas dan tinta
    default. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris::Sekretaris() : kertas(KERTAS_DEFAULT), tinta(TINTA_DEFAULT), energi(ENERGI_MAX), memoLength(0) {
    this->memo = NULL;
}
/*
    Membuat objek Sekretaris dengan nilai kertas dan tinta
    sesuai yang diberikan. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris::Sekretaris(int kertas, int tinta) : kertas(kertas), tinta(tinta), energi(ENERGI_MAX), memoLength(0) {
    this->memo = NULL;
}
/*
    Dealokasi variabel-variabel yang perlu didealokasi.
    Jika tidak perlu, hapus metode ini.
*/
Sekretaris::~Sekretaris() {
    delete[] this->memo;
}

/*
    Membuat memo dengan isi sesuai yang diberikan. Metode ini
    menggunakan metode pakaiKertas, pakaiTinta, dan pakaiEnergi.
    Untuk membuat 1 memo akan menghabiskan 1 kertas, 1 energi,
    dan tinta sebanyak jumlah karakter pesan.

    Ada beberapa penyebab memo gagal dibuat, yaitu:
    - Jika kertas habis, akan mengeluarkan pesan dari exception,
        ditambah dengan ", segera isi kertas"
    - Jika tinta kurang, akan mengeluarkan pesan dari exception,
        ditambah dengan ", segera isi tinta"
    - Jika energi habis, akan mengeluarkan pesan dari exception,
        ditambah dengan ", segera istirahat"
    - Jika pesan terlalu panjang, akan mengeluarkan pesan dari
        exception, ditambah dengan ", perpendek pesannya"

    Jika memo gagal dibuat, maka tinta, kertas, dan energi tidak
    berkurang. Gunakan metode batalPakaiKertas, batalPakaiTinta,
    dan batalPakaiEnergi.

    Jika berhasil, maka memo akan dimasukkan ke daftar memo serta
    menampilkan pesan "Memo [<nomor_memo>] untuk <untuk> berhasil
    dibuat"

    Keterangan:
    <...> -> ganti dengan nilai yang sesuai.
*/
void Sekretaris::buatMemo(string pesan, string untuk) {
    try {
        this->pakaiKertas();
        this->pakaiTinta(pesan.length());
        this->pakaiEnergi();

        Memo newMem(pesan, untuk);   

        Memo* temp = new Memo[this->memoLength];
        for (int i = 0; i < this->memoLength; i++) {
            temp[i] = this->memo[i];
        }
        delete[] this->memo;

        this->memo = new Memo[this->memoLength + 1];
        for (int i = 0; i < this->memoLength; i++) {
            this->memo[i] = temp[i];
        }
        delete[] temp;

        this->memo[this->memoLength] = newMem;
        this->memoLength++;

        cout << "Memo [" << this->memoLength << "] untuk " << newMem.getUntuk() << " berhasil dibuat" << endl;
    } catch (KertasHabisException kertasExc) {
        cout << kertasExc.what() << ", segera isi kertas" << endl;
        // throw kertasExc;
    } catch (TintaKurangException tintaExc) {
        cout << tintaExc.what() << ", segera isi tinta" << endl;
        batalPakaiKertas();
        // throw tintaExc;
    } catch (EnergiHabisException energiExc) {
        cout << energiExc.what() << ", segera istirahat" << endl;
        batalPakaiKertas();
        batalPakaiTinta(pesan.length());
        // throw energiExc;
    } catch (PesanKepanjanganException pesanExc) {
        cout << pesanExc.what() << ", perpendek pesannya" << endl;
        batalPakaiKertas();
        batalPakaiTinta(pesan.length());
        batalPakaiEnergi();
        // throw pesanExc;
    }

}
/*
    Menggunakan 1 kertas.

    Jika kertas tidak cukup, maka metode ini akan melemparkan
    KertasHabisException dan tidak ada kertas yang digunakan.
*/
void Sekretaris::pakaiKertas() {
    if (this->kertas < 1) {
        throw KertasHabisException();
    }
    this->kertas--;
}
/*
    Menggunakan tinta sebanyak num.

    Jika tinta tidak cukup, maka metode ini akan melemparkan
    TintaKurangException dan tidak ada tinta yang digunakan.
*/
void Sekretaris::pakaiTinta(int num) {
    if (this->tinta < num) {
        throw TintaKurangException();
    }
    this->tinta -= num;
}
/*
    Menggunakan 1 energi.

    Jika energi tidak cukup, maka metode ini akan melemparkan
    EnergiHabisException dan tidak ada energi yang digunakan.
*/
void Sekretaris::pakaiEnergi() {
    if (this->energi < 1) {
        throw EnergiHabisException();
    }
    this->energi--;
}
/*
    Membatalkan penggunaan 1 kertas.
*/
void Sekretaris::batalPakaiKertas() {
    this->kertas++;
}
/*
    Membatalkan penggunaan tinta sebanyak num.
*/
void Sekretaris::batalPakaiTinta(int num) {
    this->tinta += num;
}
/*
    Membatalkan penggunaan 1 energi.
*/
void Sekretaris::batalPakaiEnergi() {
    this->energi++;
}
/*
    Menambahkan jumlah tinta sebanyak num.
*/
void Sekretaris::isiTinta(int num) {
    this->tinta += num;
}
/*
    Menambahkan jumlah kertas sebanyak num.
*/
void Sekretaris::isiKertas(int num) {
    this->kertas += num;
}
/*
    Istirahat mengembalikan energi menjadi maksimum.
*/
void Sekretaris::istirahat() {
    this->energi = ENERGI_MAX;
}
/*
    Menampilkan status dari sekretaris. Berikut adalah format tampilan:
    <...> -> tampilkan nilai yang sesuai
    (...) -> komentar, tidak termasuk output

    --------------
    Status
        Energi : <jumlah_energi>
        Tinta : <jumlah_tinta>
        Kertas : <jumlah_kertas>
        Memo : <jumlah_memo>
        (untuk setiap memo ke-i, mulai dari 1)
        Memo [<i>]
            Pesan : <pesan_memo_i>
            Untuk : <untuk_memo_i>
    --------------

    (Output tidak termasuk ---------- di awal dan akhir)
*/
void Sekretaris::printStatus() {
    cout << "Status" << endl
         << "  Energi : " << this->energi << endl
         << "  Tinta : " << this->tinta << endl
         << "  Kertas : " << this->kertas << endl
         << "  Memo : " << this->memoLength << endl;
    for (int i = 0; i < this->memoLength; i++) {
        cout << "    Memo [" << i + 1 << "]" << endl;
        cout << "      Pesan : " << this->memo[i].getPesan() << endl;   
        cout << "      Untuk : " << this->memo[i].getUntuk() << endl;   
    }
}