public class BlueCard extends Card {
    // ctor
    public BlueCard(){
        super();
    }

    public BlueCard(Double number){
        super(number);
    }

    public Double value() {
        // number + 0.0C
        return this.getNumber() + 0.02;
    }

    public void printInfo() {
        System.out.print("Kartu Biru: ");
        System.out.println(this.getNumber());
    }
}
