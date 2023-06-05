public class Couple <K, V> {
    // key dan value private
    private K key;
    private V value;

    // semua method public

    public Couple(K key, V value) {
        this.key = key;
        this.value = value;
    }

    // getter setter
    // getKey, mengirimkan K
    public K getKey() {
        return this.key;
    }
    // getVal, mengirimkan V
    public V getVal() {
        return this.value;
    }
    // setKey, parameter K
    public void setKey(K key) {
        this.key = key;
    }
    // setVal, parameter V
    public void setVal(V val) {
        this.value = val;
    }

    // comparator
    public boolean isEqual(Couple<K, V> c) {
        return (
            this.key == c.key && this.value == c.value
        );
    }

    public int nearEQ(Couple<K, V> c) {
        if (this.isEqual(c)) {
            // key dan value sama
            return 3;
        } else if (this.value == c.value) {
            // hanya value yang sama
            return 2;
        } else if (this.key == c.key) {
            // hanya key yang sama
            return 1;
        } else {
            // key value berbeda
            return 0;
        }
    }
}