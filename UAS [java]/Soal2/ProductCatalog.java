import java.util.ArrayList;
import java.util.List;

public class ProductCatalog implements ProductManagement {
    private List<Product> productList;

    public ProductCatalog() {
        this.productList = new ArrayList<>();
    }

    public ProductCatalog(List<Product> pList) {
        this.productList = pList;
    }

    public void addProduct(Product p) {
        this.productList.add(p);
    }

    public Product removeProduct(int id) {
        Product result = this.getProduct(id);

        int index = -1;
        for (int i = 0; i < productList.size(); i++) {
            if (productList.get(i).getId() == id) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            productList.remove(index);
        }

        return result;
    }

    public void updateProduct(int id, String name, int price, String description) {
        for (int i = 0; i < productList.size(); i++) {
            if (productList.get(i).getId() == id) {
                productList.get(i).setName(name);
                productList.get(i).setPrice(price);
                productList.get(i).setDescription(description);
                return;
            }
        }
        System.out.println("Produk dengan id " + id + " tidak ditemukan.");
    }

    public List<Product> getAllProduct() {
        return this.productList;
    }

    public Product getProduct(int id) {
        Product result;
        for (int i = 0; i < productList.size(); i++) {
            if (productList.get(i).getId() == id) {
                result = productList.get(i);
                return result;
            }
        }
        return null;
    }
}
