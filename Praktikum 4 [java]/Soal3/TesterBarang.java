public class TesterBarang {
    public static void main(String[] arg) {
        DaftarBelanja pp = new DaftarBelanja(4);

        pp.belanja(15, "makanan dari lorong 15");
        pp.belanja(16, 3, "makanan dari lorong 16");
        pp.belanja("pisang");
        pp.belanja(20, "pisang");
        pp.belanja("pisang");

        pp.print();
    }
}