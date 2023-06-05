import java.util.List;
import java.util.ArrayList;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        this.tasks = new ArrayList<Task>();
    };

    public void addTask(Task newTask){
        this.tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            for (Task executedTask : tasks) {
                Thread.sleep(executedTask.getTime());
                synchronized (executedTask) {
                    executedTask.setStatus("done");
                    executedTask.notify();
                }
            }
        } catch (InterruptedException e) {
            System.out.println("Worker Error!");
        }
    }
    
}