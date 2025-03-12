import java.util.ArrayList;

public class Graph {
    int[][] matrix;
    ArrayList<Node> nodes;

    Graph(int size){
        matrix = new int[size][size];
        nodes = new ArrayList<>();
    }
    public void add_node(Node node){
        nodes.add(node);
    }
    public void add_edge(int src, int dst){
        matrix[src][dst] = 1;
    }
    public void print(){
        System.out.print("  ");
        for(Node node: nodes){
            System.out.printf("%c ",node.data);
        }
        System.out.println();

        for(int i = 0; i < matrix.length; i++){
            System.out.printf("%c ",nodes.get(i).data);
            for(int j = 0; j < matrix[i].length; j++){
                System.out.printf("%d ",matrix[i][j]);
            }
            System.out.println();
        }
    }
}
