import java.util.List;

public class Pasukan {
    private List<Integer> _list;
    private int _n;

    public Pasukan(List<Integer> list, int n) {
        this._n = n;
        this._list = list;
    }
    
    public void reset() {
        this._list.clear();
        for (int i = 0; i < _n; i++) {
            this._list.add(0);
        }
    }

    public long get(int idx) {
        this.reset();
        long startTime = Util.getTime();

        this._list.get(idx);

        long finishTime = Util.getTime();
        return finishTime - startTime;
    }

    public long del(int idx, int t) {
        this.reset();
        long startTime = Util.getTime();

        for (int i = 0; i < t; i++) {
            this._list.remove(idx);
        }

        long finishTime = Util.getTime();
        return finishTime - startTime;
    }

}
