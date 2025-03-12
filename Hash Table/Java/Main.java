public class Main {
    public static void main(String[] args){
        Hash_Table hash = new Hash_Table(10);

        hash.put("William",21);
        hash.put("T",19);
        hash.put("Julio",51);
        hash.put("Eliane",53);

        hash.remove("T");

        hash.print();
    }
}
