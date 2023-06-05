public class Kmain {
    public static void main(String[] args) {
        // 3+5i
        // 0
        // 3i
        // -3
        // -5-4i

        Kompleks a = new Kompleks(3,5);
        Kompleks b = new Kompleks();
        Kompleks c = new Kompleks(0,3);
        Kompleks d = new Kompleks(-3,0);
        Kompleks e = new Kompleks(-5,-4);

        a.print();
        b.print();
        c.print();
        d.print();
        e.print();
        System.out.println(Kompleks.countKompleksInstance());
        return;
    }

}
