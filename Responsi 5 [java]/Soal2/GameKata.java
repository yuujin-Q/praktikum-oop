import java.util.HashMap;
import java.util.Map;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> wordMap = new HashMap<String, Integer>();

        for (String titoWord : tito) {
            wordMap.put(titoWord, 1);
        }

        for (String wiwidWord : wiwid) {
            if (wordMap.containsKey(wiwidWord)) {
                wordMap.put(wiwidWord, 2);   
            } else {
                wordMap.put(wiwidWord, 1);
            }
        }

        // print
        for (Map.Entry<String, Integer> entry : wordMap.entrySet()) {
            if (entry.getValue() == 2) {
                System.out.println(entry.getKey());
            }
        }
    }
}