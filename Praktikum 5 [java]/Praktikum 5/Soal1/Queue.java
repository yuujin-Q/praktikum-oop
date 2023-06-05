import java.util.ArrayList;

public class Queue<T> {

  private ArrayList<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_QUEUE_SIZE = 500;



//Instantiate dengan size default

  public Queue() {
    this.data = new ArrayList<T>();
    this.size = DEFAULT_QUEUE_SIZE;
    this.lastElmIdx = -1;
  }

//Instantiate dengan size = n

  public Queue(int n) {
    this.data = new ArrayList<T>();
    this.size = n;
    this.lastElmIdx = -1;
  }

//Copy queue

  public Queue(final Queue<T> q) {
    this.data = new ArrayList<T>();
    this.size = q.size;
    this.lastElmIdx = q.lastElmIdx;

    for (int i = 0; i <= this.lastElmIdx; i++) {
        this.data.add(
            q.data.get(i)
        );
    }
  }

  public void push(T t) {
    if (this.lastElmIdx < this.size - 1) {
        this.data.add(t);
        this.lastElmIdx++;
    }
  }

  public T pop() {
    T result;
    result = this.data.get(0);
    this.data.remove(0);
    this.lastElmIdx--;
    return result;
  }

  public boolean isEmpty() {
    return (this.lastElmIdx == -1);
  }

  public boolean isFull() {
    return (this.lastElmIdx == this.size - 1);
  }

}