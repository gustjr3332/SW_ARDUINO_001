#pragma warning(disable:4996)
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//hash search implementation in C
//가장 빠른 검색 알고리즘 중 하나로, 
//해시 테이블을 사용하여 O(1)의 시간 복잡도로 데이터를 검색할 수 있습니다.
#define M 13

typedef struct HashTable {
    int table[M];
}HashTable;

void init(HashTable *ht) {
    for (int i = 0; i < M; i++) {
        ht->table[i] = 0; //각 버킷 값 0 초기화화
    }
}

int hash_function(int key) {
    return key % M; // Simple modulo hash function
}
int hash_function_2(int key) {
    return 11 - (key % 11); // double hashing
}

void insert(HashTable *ht, int key) {
    int hashVal = hash_function(key);
    while (ht->table[hashVal] != 0) { 
        hashVal = (hashVal + 1) % M;//선형 조사법
    }
    ht->table[hashVal] = key;
}
void insert_2(HashTable *ht, int key){
    int hashVal = hash_function(key);
    for(int i=0;i<M;i++){
        int b= (hashVal + i*i) % M; //이차 조사법
        //int b = (hashVal + i * hash_function_2(key)) % M; //이중 해싱
        if (ht->table[b] == 0) {
            ht->table[b] = key;
            return;
        }
    }
}

void hash_search(HashTable *ht, int key) {
    int hashVal = hash_function(key);
    while (ht->table[hashVal] != 0) {
        if (ht->table[hashVal] == key) {
            printf("Found %d at index %d\n", key, hashVal);
            return;
        }
        hashVal = (hashVal + 1) % M; //선형 조사법
    }
    printf("Key %d not found\n", key);
    
}
void delete(HashTable *ht, int key) {
    int hashVal = hash_function(key);
    while (ht->table[hashVal] != 0) {
        if (ht->table[hashVal] == key) {
            ht->table[hashVal] = 0; // Mark as deleted
            printf("Deleted %d from index %d\n", key, hashVal);
            return;
        }
        hashVal = (hashVal + 1) % M; //선형 조사법
    }
    printf("Key %d not found for deletion\n", key);
}

void print_hash_table(HashTable *ht) {
    printf("\nHash Table: ");
    for (int i = 0; i < M; i++) {
        if (ht->table[i] != 0) {
            printf(" %2d",ht->table[i]);
        } else {
            printf(" 0");
        }
        
    }
    printf("\n");
}

int main() {
    int arr[] = {45,27,88,9,71,60,46,38,24};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    HashTable ht;
    init(&ht);
    for (int i = 0; i < size; i++) {
        insert(&ht, arr[i]);
        //print_hash_table(&ht);
    }
    int val;
    scanf("%d", &val);
    hash_search(&ht, val);
    print_hash_table(&ht);

    scanf("%d", &val);
    delete(&ht, val);
    print_hash_table(&ht);

    scanf("%d", &val);
    hash_search(&ht, val);
    return 0;
}