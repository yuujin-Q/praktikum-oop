import java.util.ArrayList;
import java.util.List;

public class Subject {
    private List<Observer> observers;
    private String currentContent;

    public Subject() {
        this.observers = new ArrayList<>();
    }

    public void addObserver(Observer o) {
        this.observers.add(o);
    }

    public void removeObserver(Observer o) {
        this.observers.remove(o);
    }

    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.updateNotification(currentContent);
        }
    }

    public void updateContent(String content) {
        this.currentContent = content;
        this.notifyObservers();
    }

}