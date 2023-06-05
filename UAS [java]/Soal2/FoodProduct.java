public class FoodProduct extends Product {
    private String expiryDate;

    public FoodProduct(int id, String name, int price, String description, String expiryDate) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.description = description;
        this.expiryDate = expiryDate;
    }

    public String getExpiryDate() { return expiryDate; }

    @Override
    public String getInfo() {
        return (id + ": " + name + " - " + price + " - " + expiryDate + " - " + description);
    }
    
}
