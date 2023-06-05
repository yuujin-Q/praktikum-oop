import java.util.ArrayList;
import java.util.List;

public class BoxMain {
    public static void main(String[] args) {
        List<Object> boxElmt = new ArrayList<>();
        boxElmt.add(21);
        boxElmt.add(3.4f);
        boxElmt.add(true);
        boxElmt.add(null);
        boxElmt.add("TEST");
        boxElmt.add(null);

        Box<Object> myBox = new Box<>(boxElmt);

        System.out.println(BoxOperator.getContents(myBox, Object.class));
    }
}
