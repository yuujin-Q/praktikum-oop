import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        this.animals = new ArrayList<Animal>();
        // Inisialisasi ArrayList animals kosong
    } 

    public int getAnimalCount() {
        return this.animals.size();
        // Mengembalikan jumlah hewan dalam this.animals
    }

    public void addAnimal(Animal animal) {
        this.animals.add(animal);
        // menambahkan seekor hewan ke dalam this.animals
    }

    public Animal getAnimalAt(int i) {
        return this.animals.get(i);
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
    }

    public void removeAnimalAt(int i) {
        this.animals.remove(i);
        // menghapus hewan pada this.animals pada index i
    }

    public boolean isEmpty() {
        return this.animals.isEmpty();
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak
    }

    public void describe() {
        if (this.isEmpty()) {
            System.out.println("Kandang ini kosong...");
        } else {
            System.out.println("Kandang berisi " + this.getAnimalCount() + " ekor hewan:");
            for (int i = 0; i < getAnimalCount(); i++) {
                Animal currAnimal = this.getAnimalAt(i);
                System.out.println((i + 1) + ". " + currAnimal.getName() + ", spesies " + currAnimal.getSpecies() + ", umur " + currAnimal.getAge() + " tahun");
            }
        }
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
    }

    public void feed() {
        if (this.isEmpty()) {
            System.out.println("Kandang ini kosong...");
        } else {
            for (Animal a : this.animals) {
                a.eat();
            }
        }
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
    }

    public boolean safeForPetting() {
        for (Animal animal : this.animals) {
            if (animal.isFriendly() == false) {
                return false;
            }
        }
        return true;
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
    }
}