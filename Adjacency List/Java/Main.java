public class Main {
    public static void main(String[] args){
        Graph graph = new Graph();

        graph.add_node(new Node('A'));
        graph.add_node(new Node('B'));
        graph.add_node(new Node('C'));

        graph.add_edge(0,1);
        graph.add_edge(0,2);
        graph.add_edge(1,0);
        graph.add_edge(2,0);
        graph.add_edge(2,1);

        graph.print();
    }
}
