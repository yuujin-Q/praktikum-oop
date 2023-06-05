public class SMSObserver implements Observer {
    @Override
    public void updateNotification(String content) {
        System.out.println("SMS: " + content);
    }
}
