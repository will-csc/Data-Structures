class Graph:
    def __init__(self):
        self.alist = []
    
    def add_node(self,node: str):
        self.alist.append([node])
    
    def add_edge(self,src: int, dst: int):
        dst_node = self.alist[dst][0]
        self.alist[src].append(dst_node)
    
    def check_edge(self,src: int,dst: int):
        dst_node = self.alist[dst][0]
        return dst_node in self.alist[src]
    
    def print(self):
        for lst in self.alist:
            for node in lst:
                print(f"{node} -> ", end="")
            print("NULL")

graph = Graph()

graph.add_node('A')
graph.add_node('B')
graph.add_node('C')

graph.add_edge(0,1)
graph.add_edge(0,2)
graph.add_edge(1,0)
graph.add_edge(2,0)
graph.add_edge(2,1)

graph.print()
