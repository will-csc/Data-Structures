#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct Graph {
    Node *adjList[SIZE];
    int size;
} Graph;

void init_graph(Graph *graph) {
    for (int i = 0; i < SIZE; i++) {
        graph->adjList[i] = NULL;
    }
    graph->size = 0;
}

void add_node(Graph *graph, char data) {
    if (graph->size >= SIZE) {
        printf("Graph full\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    graph->adjList[graph->size] = newNode;
    graph->size++;
}

void add_edge(Graph *graph, int src, int dst) {
    if (src >= graph->size || dst >= graph->size) {
        printf("Invalid edge\n");
        return;
    }

    Node *dstNode = graph->adjList[dst];
    Node *srcNode = graph->adjList[src];

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = dstNode->data;
    newNode->next = NULL;

    while (srcNode->next != NULL) {
        srcNode = srcNode->next;
    }
    srcNode->next = newNode;
}

bool check_edge(Graph *graph, int src, int dst) {
    if (src >= graph->size || dst >= graph->size) {
        return false;
    }

    Node *srcNode = graph->adjList[src];
    char dstData = graph->adjList[dst]->data;

    while (srcNode != NULL) {
        if (srcNode->data == dstData) {
            return true;
        }
        srcNode = srcNode->next;
    }
    return false;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        Node *current = graph->adjList[i];
        while (current != NULL) {
            printf("%c -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph graph;
    init_graph(&graph);

    add_node(&graph, 'A');
    add_node(&graph, 'B');
    add_node(&graph, 'C');

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 0);
    add_edge(&graph, 2, 0);
    add_edge(&graph, 2, 1);

    print_graph(&graph);

    return 0;
}
