struct Graph{
    size: usize,
    matrix: Vec<Vec<i32>>,
    nodes: Vec<char>,
}
impl Graph{
    fn new(size: usize) -> Graph{
        Graph{
            size,
            matrix: vec![vec![0;size];size],
            nodes: Vec::new(), 
        }
    }
    fn add_node(&mut self,node: char){
        if self.size == self.nodes.len() {
            println!("The graph is full!");
        }else{
            self.nodes.push(node);
        }
    }
    fn add_edge(&mut self,src: usize, dst: usize){
        if src < self.size && dst < self.size {
            self.matrix[src][dst] = 1;
        }else{
            println!("Error adding the edge, source or destination greater than size!")
        }
    }
    fn check_edge(&mut self,src: usize, dst: usize) -> bool{
        if src < self.size && dst < self.size {
            if self.matrix[src][dst] == 1 {
                return true;
            }
            return false;
        }
        return false;
    }
    fn print_graph(&self){
        //Imprimir as colunas
        print!("  ");
        for i in 0..self.size{
            print!("{} ",self.nodes[i]);
        }
        println!();

        //Imprime as linhas
        for i in 0..self.size{
            print!("{} ",self.nodes[i]);
            for j in 0..self.size{
                print!("{} ",self.matrix[i][j]);
            }
            println!();
        }
    }
}

fn main(){
    let mut graph = Graph::new(3);

    graph.add_node('A');
    graph.add_node('B');
    graph.add_node('C');

    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,0);
    graph.add_edge(2,0);
    graph.add_edge(2,1);

    graph.check_edge(0,1);

    graph.print_graph();
}
