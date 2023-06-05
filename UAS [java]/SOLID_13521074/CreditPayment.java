public class CreditPayment implements PaymentProcessor {
    public void processPayment(double amount) {
        // Process payment logic
        System.out.println("Payment processed successfully with credit card: $" + amount);
    }
}
