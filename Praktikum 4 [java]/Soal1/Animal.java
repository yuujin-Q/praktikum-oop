/**
 * Animal.java
 * kelas abstrak dari hewan, diturunkan jadi jenis hewan
 * @author 13521074 Eugene Yap Jin Quan
 */

public abstract class Animal implements Comparable<Animal> {
    protected int numberOfLegs;
    protected long children;

    public Animal(int numberOfLegs) {
        this.numberOfLegs = numberOfLegs;
        this.children = 0; 
    }

    public int getNumberOfLegs() {
        return this.numberOfLegs;
    } 
    public long getNumberOfChildren() {
        return this.children;
    }

    public void increaseChild(int increment) {
        this.children += increment;
    }

    public abstract int getAnimalPower();
    
    public int compareTo(Animal a) {
        // compareTo mengembalikan:
        // 0 bila this sama dengan m
        // 1 bila this lebih dari m
        // -1 bila this kurang dari m
        if (this.getAnimalPower() < a.getAnimalPower()) {
            return -1;
        } else if (this.getAnimalPower() == a.getAnimalPower()) {
            return 0;
        } else {
            return 1;
        }
    }
}
