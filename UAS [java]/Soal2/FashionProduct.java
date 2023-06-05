public class FashionProduct extends Product {
    private String size;

    
    public FashionProduct(int id, String name, int price, String description, String size) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.description = description;
        this.size = size;
    }
    
    public String getSize() { return size; }

    @Override
    public String getInfo() {
        return (id + ": " + name + " - " + price + " - " + size + " - " + description);
    }
}
