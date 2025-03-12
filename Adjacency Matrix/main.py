class Graph:
    def __init__(self,size: int):
        self.matrix = [[0 for i in range(size)] for j in range(size)]
        self.nodes = []
    
    def add_node(self,node: str):
        self.nodes.append(node)

    def add_edge(self,src: int, dst: int):
        self.matrix[src][dst] = 1
    
    def check_edge(self,src: int, dst: int):
        if self.matrix[src][dst] == 1:
            return True
        return False

    def print(self):
        #Imprimir colunas
        print("  ",end="")
        for node in self.nodes:
            print(f"{node} ",end="")
        print()
        
        #Imprimir linhas
        size = len(self.matrix)
        for i in range(size):
            print(f"{self.nodes[i]} ",end="")
            for j in range(size):
                print(f"{self.matrix[i][j]} ",end="")
            print()

graph = Graph(3)

graph.add_node("A")
graph.add_node("B")
graph.add_node("C")

graph.add_edge(0,1)
graph.add_edge(0,2)
graph.add_edge(1,0)
graph.add_edge(2,0)
graph.add_edge(2,1)

graph.print()