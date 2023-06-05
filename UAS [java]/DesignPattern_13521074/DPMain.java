public class DPMain {
    public static void main(String[] args) {
        EmailObserver eo = new EmailObserver();
        PushNotificationObserver po = new PushNotificationObserver();
        SMSObserver so = new SMSObserver();

        Subject subject = new Subject();
        subject.addObserver(eo);
        subject.addObserver(po);
        subject.addObserver(so);

        subject.updateContent("Hello world");
        subject.updateContent("Goodbye world");
    }
}
