public class YellowCard extends Card {
    // ctor
    public YellowCard(){
        super();
    }

    public YellowCard(Double number){
        super(number);
    }

    public Double value() {
        // number + 0.0C
        return this.getNumber() + 0.03;
    }

    public void printInfo() {
        System.out.print("Kartu Kuning: ");
        System.out.println(this.getNumber());
    }
}
