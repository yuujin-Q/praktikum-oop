public class PushNotificationObserver implements Observer {
    @Override
    public void updateNotification(String content) {
        System.out.println("Push Notification: " + content);
    }
    
}
