public class TempatTinggal {
    protected int luas;   // meter persegi
    protected double hargaBahanBangunan;  // harga/m2

    // ctor
    public TempatTinggal() {
        this.luas = 0;
        this.hargaBahanBangunan = 0;
    }
    public TempatTinggal(int luas, double harga) {
        this.luas = luas;
        this.hargaBahanBangunan = harga;
    }

    // getter
    public int getLuas() {
        return this.luas;
    }
    public double getHargaBahanBangunan() {
        return this.hargaBahanBangunan;
    }
    // setter
    public void setLuas(int luas) {
        this.luas = luas;
    }
    public void setHargaBahanBangunan(double harga) {
        this.hargaBahanBangunan = harga;
    }

    // hitung biaya
    public double hitungBiayaBangun() {
        return this.luas * this.hargaBahanBangunan;
    }

}

class Rumah extends TempatTinggal {
    // ctor
    public Rumah() {
        super();
    }
    public Rumah(int luas, double harga) {
        super(luas, harga);
    }
    public Rumah(int lebar, int panjang, double harga) {
        super(lebar * panjang, harga);
    }

    // setter
    public void setLuas(int panjang, int lebar) {
        this.setLuas(panjang * lebar);
    }

    // biaya dan ormas
    public double hitungBiayaBangun(double biayaOrmas) {
        return this.hitungBiayaBangun() + biayaOrmas;
    }    
}

interface Kendaraan {
    public float hitungJarakTempuh();    
}

class Karavan extends TempatTinggal implements Kendaraan {
    private float bensin;   // liter
    private float pemakaianBensin;  // jarak/liter

    public Karavan() {
        super();
        this.bensin = 0;
        this.pemakaianBensin = 0;
    }
    public Karavan(int luas, double harga, float bensin, float pemakaianBensin) {
        super(luas, harga);
        this.bensin = bensin;
        this.pemakaianBensin = pemakaianBensin;
    }

    // getter
    public float getBensin() {
        return this.bensin;
    }
    public float getPemakaianBensin() {
        return this.pemakaianBensin;
    }
    // setter
    public void setBensin(float bensin) {
        this.bensin = bensin;
    }
    public void setPemakaianBensin(float pemakaian) {
        this.pemakaianBensin = pemakaian;
    }

    // hitung biaya
    public double hitungBiayaBangun() {
        return this.getLuas() * this.getHargaBahanBangunan() * 3;
    }
    // hitung jarak
    public float hitungJarakTempuh() {
        return this.getBensin() * this.getPemakaianBensin();
    }
}
