import java.util.ArrayList;
import java.util.List;

public class ShoppingCart {
    private List<Product> cart;

    public ShoppingCart() {
        this.cart = new ArrayList<>();
    }

    public void addProduct(Product product) {
        cart.add(product);
    }
 
 
    public void removeProduct(Product product) {
        cart.remove(product);
    }
 
 
    public double calculateTotalPrice() {
        double total = 0;
        for (Product product : cart) {
            total += product.getPrice();
            total += product.calculateTax();
        }
        return total;
    }
}
