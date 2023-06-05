import java.util.List;

public interface ProductManagement {
    void addProduct(Product p);
    Product removeProduct(int id);
    void updateProduct(int id, String name, int price, String description);
    List<Product> getAllProduct();
    Product getProduct(int id);
}
