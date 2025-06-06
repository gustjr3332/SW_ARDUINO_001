#pragma warning disable C4996
#include <stdio.h>
#include <stdlib.h>


//연결리스트 그룹화 사용

#include <time.h>

#define N 100

typedef int element;
typedef char group;

typedef struct Node {
    element data;
    group group; 
    struct Node *prev; 
    struct Node *next;
} Node;

typedef struct DListType {
    Node *H; // 헤더 노드
    Node *T; // 꼬리 노드
    int size;   // 리스트 크기
} DListType;

// 노드 생성

Node *makeNode(group g, element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->group = g;
    node->prev = NULL; 
    node->next = NULL;
    return node;
}

void init(DListType *DL) {
    DL->H = (Node *)malloc(sizeof(Node));
    DL->H->next = DL->T;
    DL->H->prev = NULL;
    DL->T = (Node *)malloc(sizeof(Node));  
    DL->T->prev = DL->H;
    DL->T->next = NULL; 

    DL->size = 0;                           
}//헤드 노드,테일 노드 버전

int isEmpty(DListType *DL){
    return DL->size == 0;//logical  0 or 1
}


int isFull(DListType *DL){
    return DL->size == N;//logical  0 or 1
}



void insertLast(DListType *DL,group g, element e) {
    
    Node *node = makeNode(g,e);
    Node *p = DL->T; 

    node->prev = p->prev;

    node->next = p;

    p->prev->next = node; 

    p->prev = node;

    DL->size++;
    
}
void deleteNode(DListType *DL, Node *p) {
    if (p == NULL) return;
    p->prev->next = p->next;
    p->next->prev = p->prev; 
    free(p); // 현재 노드 메모리 해제
    DL->size--;
}
element deletegroup(DListType *DL,group g) {
    Node *p = DL->H->next; 
    while(p != DL->T) {
        if (p->group == g ) {
            element e = p->data;
            deleteNode(DL, p);
            printf("%c is deleted.\n\n", g);
            return e;
        }
        p = p->next;
    }
    printf("not found\n");
}

void print(DListType *DL) {
    /*
    for(int i = 0; i < DL->size; i++){
        printf("%c ", p->data);
        p = p->next;
    }
    */
    for(Node *p = DL->H->next;p!=DL->T;p=p->next){
        printf("%c %d\n", p->group,p->data);
    }

    printf("\n");
}

int main() {
    DListType Dlist;
    init(&Dlist);
    srand(time(NULL));
    group g[11] = {'A','B','C','D','E','F','G','H','I','J'};
    for(int i = 0; i < 10; i++){
        element e = rand() % 10;
        g[i] = 'A' + i; 
        insertLast(&Dlist,g[i],e);
    }
    
    print(&Dlist);
    deletegroup(&Dlist,'D');
    print(&Dlist);
}
