public class Main {
    public static void main(String[] args){
        Graph graph = new Graph(7);

        graph.add_node(new Node('A'));
        graph.add_node(new Node('B'));
        graph.add_node(new Node('C'));
        graph.add_node(new Node('D'));
        graph.add_node(new Node('E'));
        graph.add_node(new Node('F'));
        graph.add_node(new Node('G'));

        graph.add_edge(0,1);
        graph.add_edge(0,3);
        graph.add_edge(0,6);
        graph.add_edge(1,5);
        graph.add_edge(2,5);
        graph.add_edge(3,5);
        graph.add_edge(5,3);
        graph.add_edge(6,1);
        graph.add_edge(6,2);

        graph.print();
    }
}
