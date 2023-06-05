public class RedCard extends Card {
    // ctor
    public RedCard(){
        super();
    }

    public RedCard(Double number){
        super(number);
    }

    public Double value() {
        // number + 0.0C
        return this.getNumber() + 0.04;
    }

    public void printInfo() {
        System.out.print("Kartu Merah: ");
        System.out.println(this.getNumber());
    }
}
