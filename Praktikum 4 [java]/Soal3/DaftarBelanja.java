public class DaftarBelanja {
    private Barang[] listBelanja;
    private Integer max_items;
    private Integer item_count;

    public DaftarBelanja(Integer max_items) {
        this.max_items = max_items;
        this.listBelanja = new Barang[this.max_items];
        this.item_count = 0;
    }

    // belanja barang "keterangan (lorong x)" sejumlah 1
    public void belanja(int lorong, String keterangan) {
        this.belanja(lorong, 1, keterangan);
    }

    // belanja barang "keterangan (lorong x)" sejumlah qty
    public void belanja(int lorong, int qty, String keterangan) {
        String item_name = keterangan + " (lorong " + lorong + ")";
        this.belanja(item_name, qty);
    }

    // belanja barang "barang" sejumlah 1
    public void belanja(String barang) {
        this.belanja(barang, 1);
    }

    // belanja barang "barang" sejumlah qty
    public void belanja(String barang, int qty) {
        if (this.item_count < this.max_items) {
            this.listBelanja[this.item_count] = new Barang(barang, qty);
            this.item_count++;
        }
    }

    public void print() {
        for (int i = 0; i < this.item_count; i++) {
            // print index
            System.out.print(i + 1);
            System.out.print(". ");

            // print item description
            System.out.println(this.listBelanja[i].toString());
        }
    }
}