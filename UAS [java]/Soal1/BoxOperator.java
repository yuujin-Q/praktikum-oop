import java.util.ArrayList;
import java.util.List;

public class BoxOperator {
    public static <T> List<T> getContents(Box<?> box, Class<T> type) {
        // Implement this function.
        // Case need to be handled: Box may contains null value, please make sure it is not returned.
        List<T> result = new ArrayList<>();
        for (Object element : box.getContents()) {
            if (element == null) {
                continue;
            }
            if (type.isAssignableFrom(element.getClass())) {
                result.add(type.cast(element));
            }
        }
        
        return result;
    }
}