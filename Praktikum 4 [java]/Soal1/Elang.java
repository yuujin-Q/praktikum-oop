/**
 * Elang.java
 * elang, turunan hewan
 * @author 13521074 Eugene Yap Jin Quan
 */

public class Elang extends Animal {
    protected int basePower;
    protected int jumlahTelur;

    public Elang(int basePower) {
        super(2);
        this.basePower = basePower;
        this.jumlahTelur = 0;
    }

    public int getJumlahTelur() {
        return this.jumlahTelur;
    }

    public void bertelur() {
        this.jumlahTelur++;
    }

    public int getAnimalPower() {
        return this.basePower * (int)(this.children) - this.jumlahTelur;
    }
}
