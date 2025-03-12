import java.util.LinkedList;

public class Hash_Table {
    private int size;
    private LinkedList<Entry<String, Integer>>[] table;

    Hash_Table(int size){
        this.size = size;
        table = new LinkedList[size];
        for(int i = 0; i < this.size; i++){
            table[i] = new LinkedList<>();
        }
    }

    private int hash(String key) {
        return Math.abs(key.hashCode() % size);
    }

    public void put(String key, int value){
        int idx = hash(key);
        table[idx].add(new Entry(key,value));
    }

    public int get(String key){
        int idx = hash(key);

        for(Entry entry : table[idx]){
            if(entry.key.equals(key)){
                return entry.value;
            };
        }

        return -1;
    }

    public void remove(String key){
        int idx = hash(key);
        table[idx].removeIf(entry -> entry.key.equals(key));
    }

    public void print(){
        for(int i = 0; i < size; i++){
            System.out.printf("Bucket %d: ",i+1);
            System.out.print("[ ");

            for(Entry entry : table[i]){
                System.out.printf("(%s,%d) ",entry.key,entry.value);
            }
            System.out.println("]");
        }
    }
}
