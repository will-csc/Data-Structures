#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node{
    char data;
} Node;
typedef struct Graph{
    Node *nodes[SIZE];
    int matrix[SIZE][SIZE];
    int node_count;
} Graph;

void init_graph(Graph *graph) {
    // Inicializa o gráfico, com nós como NULL e a matriz de adjacência com 0
    for (int i = 0; i < SIZE; i++) {
        graph->nodes[i] = NULL;
        for (int j = 0; j < SIZE; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    graph->node_count = 0;  // Inicializa o contador de nós
}
void add_edge(Graph *graph,int src,int dst){
    graph->matrix[src][dst] = 1;
}
void add_nodes(Graph *graph, char node){
    if (graph->node_count < SIZE) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = node;
        graph->nodes[graph->node_count] = new_node;
        graph->node_count++;
    } else {
        printf("Limite de nós atingido!\n");
    }
}
void print(Graph *graph){
    printf("  ");
    for(int i = 0; i < graph->node_count; i++) {
        printf("%c ", graph->nodes[i]->data);
    }
    printf("\n");

    for (int i = 0; i < graph->node_count; i++) {
        printf("%c ", graph->nodes[i]->data);
        for (int j = 0; j < graph->node_count; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    Graph graph;
    init_graph(&graph);

    add_nodes(&graph,'A');
    add_nodes(&graph,'B');
    add_nodes(&graph,'C');

    add_edge(&graph,0,1);
    add_edge(&graph,0,2);
    add_edge(&graph,1,0);
    add_edge(&graph,2,0);
    add_edge(&graph,2,1);

    print(&graph);
}