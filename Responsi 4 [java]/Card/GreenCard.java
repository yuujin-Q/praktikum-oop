public class GreenCard extends Card {
    // ctor
    public GreenCard(){
        super();
    }

    public GreenCard(Double number){
        super(number);
    }

    public Double value() {
        // number + 0.0C
        return this.getNumber() + 0.01;
    }

    public void printInfo() {
        System.out.print("Kartu Hijau: ");
        System.out.println(this.getNumber());
    }
}
