public class EmailObserver implements Observer {
    @Override
    public void updateNotification(String content) {
        System.out.println("Email: " + content);
    }    
}
