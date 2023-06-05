/**
 * Kompleks
 */
class Kompleks {
    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    // ctor tanpa parameter
    // inisialisasi seluruh koefisien dengan nilai 0
    public Kompleks() {
        this.real = 0;
        this.imaginer = 0;
        n_kompleks++;
    }

    // ctor dengan parameter
    public Kompleks(int real, int imaginer) {
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks++;
    }
    
    // mengembalikan bagian riil
    public int getReal() {
        return this.real;
    }
    // mengembalikan bagian imaginer
    public int getImaginer() {
        return this.imaginer;
    }

    // mengisi bagian riil
    public void setReal(int real) {
        this.real = real;
    }

    // mengisi bagian imaginer
    public void setImaginer(int imaginer) {
        this.imaginer = imaginer;
    }

    // operator+ untuk melakukan penjumlahan dengan rumus berikut
    public Kompleks plus(Kompleks b) {
        int r = this.getReal() + b.getReal();
        int i = this.getImaginer() + b.getImaginer();
        return new Kompleks(r, i);
    }
    // operator- untuk melakukan pengurangan dengan rumus berikut
    public Kompleks minus(Kompleks b) {
        int r = this.getReal() - b.getReal();
        int i = this.getImaginer() - b.getImaginer();
        return new Kompleks(r, i);
    }
    // operator* untuk melakukan perkalian dengan rumus berikut
    public Kompleks multiply(Kompleks b) {
        int r = this.getReal() * b.getReal() - this.getImaginer() * b.getImaginer();
        int i = this.getImaginer() * b.getReal() + this.getReal() * b.getImaginer();
        return new Kompleks(r, i);
    }
    // operator* untuk mengkalikan bilangan kompleks dengan konstanta
    public Kompleks multiply(int c) {
        return new Kompleks(c * this.getReal(), c * this.getImaginer());
    }

    // mengembalikan jumlah instance yang pernah dibuat
    public static int countKompleksInstance() {
        return n_kompleks;
    }

    // mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line
    // contoh:
    // 3+5i
    // 0
    // 3i
    // -3
    // -5-4i
    public void print() {
        if (this.getReal() == 0 && this.getImaginer() == 0) {
            System.out.println(0);
        } else {
            if (this.getReal() != 0) {
                System.out.print(this.getReal());
            }
            
            if (this.getImaginer() != 0) {
                if (this.getImaginer() > 0 && this.getReal() != 0) {
                    System.out.print('+');
                }
                System.out.print(this.getImaginer());
                if (this.getImaginer() != 0) {
                    System.out.print('i');
                }
            }
            System.out.println();
        }
    }
}