public class ElectronicProduct extends Product {
    private String warrantyPeriod;

    public ElectronicProduct(int id, String name, int price, String description, String warrantyPeriod) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.description = description;
        this.warrantyPeriod = warrantyPeriod;
    }

    public String getWarrantyPeriod() { return warrantyPeriod; }

    @Override
    public String getInfo() {
        return (id + ": " + name + " - " + price + " - " + warrantyPeriod + " - " + description);
    }
    
}
