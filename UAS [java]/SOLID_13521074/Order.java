public class Order {
    private ShoppingCart shoppingCart;
    private PaymentProcessor paymentProcessor;
 
 
    public Order(ShoppingCart shoppingCart, PaymentProcessor paymentMethod) {
        this.shoppingCart = shoppingCart;
        this.paymentProcessor = paymentMethod;
    }
 
 
    public void checkout(String checkoutMethod) {
        double totalPrice = shoppingCart.calculateTotalPrice();

        paymentProcessor.processPayment(totalPrice);
    }

    public void setPaymentMethod(PaymentProcessor paymentMethod) {
        this.paymentProcessor = paymentMethod;
    }
}
 