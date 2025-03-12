import java.util.ArrayList;
import java.util.LinkedList;

public class Graph {
    ArrayList<LinkedList<Node>> alist;

    Graph(){
        alist = new ArrayList<>();
    }

    public void add_node(Node node){
        LinkedList<Node> new_node = new LinkedList<>();
        new_node.add(node);
        alist.add(new_node);
    }

    public void add_edge(int src, int dst){
        LinkedList<Node> src_node = alist.get(src);
        Node dst_node = alist.get(dst).get(0);
        src_node.add(dst_node);
    }

    public boolean check_edge(int src, int dst){
        LinkedList<Node> src_node = alist.get(dst);
        Node dst_node = alist.get(dst).get(0);

        for(Node node: src_node){
            if(node == dst_node){
                return true;
            }
        }
        return false;
    }

    public void print(){
        for(LinkedList<Node> link_node : alist){
            for(Node node: link_node){
                System.out.printf("%c -> ",node.data);
            }
            System.out.println("NULL");
        }
    }
}
