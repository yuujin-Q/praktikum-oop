/**
 * Gajah.java
 * gajah, turunan hewan
 * @author 13521074 Eugene Yap Jin Quan
 */

public class Gajah extends Animal {
    protected int basePower;
    protected int age;

    public Gajah(int basePower, int age) {
        super(4);
        this.basePower = basePower;
        this.age = age;
    }

    public int getAge() {
        return this.age;
    }

    public int getAnimalPower() {
        return 3 * (this.basePower + this.age + (int)(this.children));
    }
}
