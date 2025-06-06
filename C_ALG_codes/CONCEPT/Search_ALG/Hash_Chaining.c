#pragma warning(disable:4996)
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//hash search implementation in C
//hash table 오버플로 처리 방법 : 2.체이닝(Chaining)
#define M 13

typedef struct Node {
    int key;
    struct Node *next;
}Node;

typedef struct HashTable {
    Node *head[M]; //각 버킷은 연결 리스트로 구현
}HashTable;

void init(HashTable *ht) {
    for (int i = 0; i < M; i++) {
        ht->head[i] = NULL; //각 버킷 초기화
    }
}

int hash_function(int key) {
    return key % M; // Simple modulo hash function
}
void insert(HashTable *ht, int key) {
    int hashVal = hash_function(key);
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = ht->head[hashVal];
    ht->head[hashVal] = node; //체이닝 방식으로 연결
}
void print_table(HashTable *ht) {
    for (int i = 0; i < M; i++) {
        Node *current = ht->head[i];
        printf("Bucket %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}
int main() {
    HashTable ht;
    init(&ht);
    
    insert(&ht, 1);
    insert(&ht, 14);
    insert(&ht, 27);
    insert(&ht, 2);
    insert(&ht, 15);
    
    print_table(&ht);
    
    return 0;
}