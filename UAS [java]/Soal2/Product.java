public abstract class Product {
    protected int id;
    protected String name;
    protected int price;
    protected String description;

    public int getId() { return id; }
    public String getName() { return name; }
    public int getPrice() { return price; }
    public String getDescription() { return description; }

    public void setId(int newId) { id = newId; }
    public void setName(String newName) { name = newName; }
    public void setPrice(int newPrice) { price = newPrice; }
    public void setDescription(String newDescription) { description = newDescription; }
    
    public abstract String getInfo();

}
