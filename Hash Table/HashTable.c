#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Node{
    char *key;
    int value;
    struct Node *next;
} node;

typedef struct hash_table{
    node *nodes[SIZE];
} hash_table;

int hash(char *key){
    unsigned int hash_v = 0;
    int c;
    while((c = *key++)){
        hash_v = hash_v * 31 + c;
    }
    return hash_v % SIZE;
}

void put(hash_table *htable ,char *key, int value){
    int idx = hash(key);

    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = strdup(key); // Duplica a string da chave
    new_node->value = value;
    new_node->next = NULL;

    if(htable->nodes[idx] == NULL){
        htable->nodes[idx] = new_node;
    }else{
        new_node->next = htable->nodes[idx];
        htable->nodes[idx] = new_node;
    }
}

int get(hash_table *htable ,char *key){
    int idx = hash(key);

    node *current = htable->nodes[idx];
    while(current){
        if(strcmp(current->key,key) == 0){
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void remove_key(hash_table *htable ,char *key){
    int idx = hash(key);

    node *current = htable->nodes[idx];
    node *prev = NULL;

    while(current){
        if(strcmp(current->key, key) == 0){
            if(prev == NULL){
                htable->nodes[idx] = current->next;
            }else{
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void print_hashtable(hash_table *htable){
    for(int i = 0; i < SIZE; i++){
        printf("Bucket %d: [ ",i+1);

        node *current = htable->nodes[i];
        while(current){
            printf("(%s,%d) -> ",current->key,current->value);
            current = current->next;
        }
        printf("NULL ]\n");
    }
}
void init_table(hash_table *htable) {
    for (int i = 0; i < SIZE; i++) {
        htable->nodes[i] = NULL; // Inicializa todos os ponteiros como NULL
    }
}

int main(void){
    hash_table dict;
    init_table(&dict);

    put(&dict,"William",21);
    put(&dict,"Cesar",90);
    put(&dict,"Silva",23);
    put(&dict,"De",26);
    put(&dict,"Carvalho",30);

    printf("The key %s has the value of: %d\n\n","William",get(&dict,"William"));

    print_hashtable(&dict);
}