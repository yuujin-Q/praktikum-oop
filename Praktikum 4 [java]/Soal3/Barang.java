public class Barang {
    private String name;
    private Integer amount;

    public Barang(String name, Integer amount) {
        this.name = name;
        this.amount = amount;
    }

    public String toString() {
        String result;
        result = this.amount + " " + this.name;
        return result;
    }
}