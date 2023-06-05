public class CashPayment implements PaymentProcessor {
    public void processPayment(double amount) {
        // Process payment logic
        System.out.println("Payment processed successfully with cash: $" + amount);
    }
}
