import java.lang.Comparable;
class MataKuliah implements Comparable<MataKuliah> {
    private float rating;
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;
    
    // ctor
    public MataKuliah(float rating) {
        this.rating = rating;
    }
    public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating) {
        this.nama = nama;
        this.kodeJurusan = kodeJurusan;
        this.tahunPengambilan = tahunPengambilan;
        this.rating = rating;
    }

    // getter
    public float getRating() {
        return this.rating;
    }
    public String getNama() {
        return this.nama;
    }
    public int getKodeJurusan() {
        return this.kodeJurusan;
    }
    public int getTahunPengambilan() {
        return this.tahunPengambilan;
    }

    public int compareTo(MataKuliah m) {
        // compareTo mengembalikan:
        // 0 bila this sama dengan m
        // 1 bila this lebih dari m
        // -1 bila this kurang dari m
        if (this.getKodeJurusan() == m.getKodeJurusan()
            && this.getTahunPengambilan() == m.getTahunPengambilan()
            && this.getRating() == m.getRating()) {
            return 0;
        } else if (this.getKodeJurusan() < m.getKodeJurusan()) {
            return -1;
        } else if (this.getKodeJurusan() == m.getKodeJurusan()) {
            if (this.getTahunPengambilan() < m.getTahunPengambilan()) {
                return -1;
            } else if (this.getTahunPengambilan() == m.getTahunPengambilan() && this.getRating() < m.getRating()) {
                return -1;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
}