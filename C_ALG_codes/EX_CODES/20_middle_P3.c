#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>


typedef int element;

typedef struct Node {
    element data;
    struct Node *next;
} Node;

typedef struct ListType {
    Node *head; // 헤더 노드
    int size;   // 리스트 크기
} ListType;

void init(ListType *L) {
    L->head = (Node *)malloc(sizeof(Node));
    L->head->next = NULL;
    L->size = 0;
} //헤드 노드 버전

Node* makeNode(element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
} //노드 생성

void insert(ListType *L,int pos, element e) {
    
    Node *node = makeNode(e);
    Node *p = L->head; // 헤더 노드부터 시작
    for(int i = 1; i <= pos; i++) {
        p = p->next;
    }

    node->next = p->next;
    p->next = node;
    L->size++;

} 
void sort(ListType *L) {
    Node *i, *j;
    element temp;

    for (i = L->head->next; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void print(ListType *L) {
    Node *p = L->head->next; //헤더 노드 다음 노드부터 시작
    for(int i = 0; i < L->size; i++){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
} 
int main() {
    ListType L;
    init(&L);
    int N =0,data=0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        insert(&L,i,data);
    }
    sort(&L);
    print(&L);
    return 0;
}