import java.util.ArrayList;
import java.util.List;
import java.lang.Class;
import java.lang.reflect.*;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        try {
            Class<?> ghost = Class.forName("Ghost");
            Method[] methods = ghost.getDeclaredMethods();

            ArrayList<String> methodNames = new ArrayList<>();
            for (Method method : methods) {
                String name = method.getName();
                methodNames.add(name);
            }
            return methodNames;
            
        } catch (ClassNotFoundException e) {
            return new ArrayList<>();
        }

    }   

    public Integer sumGhost() throws Exception{
        Integer sum = 0;
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] methods = ghostClass.getDeclaredMethods();
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();
        for (Method method : methods) {
            method.setAccessible(true);
            if (method.getReturnType() == Integer.class) {
                sum += (Integer) method.invoke(ghostInstance);
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception{
        StringBuilder sb = new StringBuilder();
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] methods = ghostClass.getDeclaredMethods();
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();
        for (Method method : methods) {
            method.setAccessible(true);
            if (method.getReturnType() == String.class) {
                sb.append((String) method.invoke(ghostInstance));
            }
        }
        return sb.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        for (Secret secret : sl) {
            if (secret.isThis(email)) {
                Field uniqueIdField = Secret.class.getDeclaredField("uniqueId");
                uniqueIdField.setAccessible(true);
                return (String) uniqueIdField.get(secret);
            }
        }
        return "NaN";
    }
}