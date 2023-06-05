public class Main {
    public static void main(String[] args) {
        Enclosure<Panda> enc1 = new Enclosure<Panda>();
        Panda panda1 = new Panda("po", 5);
        Panda panda2 = new Panda("po2", 5);
        enc1.addAnimal(panda1);
        enc1.addAnimal(panda2);
        enc1.addAnimal(panda2);
        enc1.describe();

        Enclosure<Lion> enc2 = new Enclosure<Lion>();
        Lion lion1 = new Lion("tigger", 5);
        Lion lion2 = new Lion("tigger2", 5);
        enc2.addAnimal(lion1);
        enc2.addAnimal(lion2);
        enc2.describe();

        Enclosure<Animal> enc3 = new Enclosure<Animal>();
        enc3.describe();

        Enclosure<Animal> enc4 = new Enclosure<Animal>();
        Panda panda3 = new Panda("po", 5);
        Lion lion3 = new Lion("tigger3", 5);
        enc4.addAnimal(panda3);
        enc4.addAnimal(lion3);
        enc4.describe();

        Zoo myZoo = new Zoo();
        System.out.println(myZoo.getTicketPrice());
        myZoo.addEnclosure(enc1);
        myZoo.addEnclosure(enc2);
        myZoo.addEnclosure(enc3);
        myZoo.addEnclosure(enc4);
        myZoo.updateTicketPrice();
        System.out.println(myZoo.getTicketPrice());
        System.out.println(myZoo.getTotalAnimalCount());
        System.out.println(myZoo.getEnclosureCount());
    }
}
