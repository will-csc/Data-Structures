use std::collections::LinkedList;

struct Graph{
    alist: Vec<LinkedList<char>>,
}
impl Graph{
    fn new() -> Self{
        Self{
            alist: Vec::new(),
        }
    }

    fn add_node(&mut self,node: char){
        let mut new_node = LinkedList::new();
        new_node.push_back(node);
        self.alist.push(new_node);
    }

    fn add_edge(&mut self, src: usize, dst: usize){
        let size = self.alist.len();

        if src < size && dst < size{
            let dst_node = self.alist[dst].front().copied().unwrap();
            self.alist[src].push_back(dst_node);
        }        
    }

    fn check_edge(&self, src: usize, dst: usize){
        let size = self.alist.len();

        if src < size && dst < size{
            let dst_node = self.alist[dst].front().copied().unwrap();

            if self.alist[src].contains(&dst_node){
                println!("Edge ({},{}) exist!",src,dst);
            }else{
                println!("Edge ({},{}) does not exist!",src,dst);
            }
        }
    }
    fn print(&self){
        println!("\nGraph:");
        for list in self.alist.iter(){
            for node in list{
                print!("{} -> ",node);
            }
            println!("NULL");
        }
    }
}

fn main(){
    let mut graph = Graph::new();

    graph.add_node('A');
    graph.add_node('B');
    graph.add_node('C');

    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,0);
    graph.add_edge(2,0);
    graph.add_edge(2,1);

    graph.check_edge(1,0);

    graph.print();
}