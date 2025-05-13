#pragma warning disable C4996
#include <stdio.h>
#include <stdlib.h>

//부리스트**많이 사용됨

#include <time.h>

#define N 100

typedef char element;


typedef struct Node {
    element data;
    struct Node *prev; 
    struct Node *next;
} Node;

typedef struct DListType {
    Node *H[N]; // 헤더 노드 배열
    Node *T[N]; // 꼬리 노드 배열
    int size;   // 리스트 크기
} DListType;

// 노드 생성

Node *makeNode(element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->prev = NULL; 
    node->next = NULL;
    return node;
}

void init(DListType *DL) {
    for(int i = 0; i < N; i++) {
        DL->H[i] = (Node *)malloc(sizeof(Node));
        DL->H[i]->next = DL->T[i];
        DL->H[i]->prev = NULL;
        DL->T[i] = (Node *)malloc(sizeof(Node)); 
        DL->T[i]->prev = DL->H[i];
        DL->T[i]->next = NULL; 
    }
    

    DL->size=0;                           
}//헤드 노드,테일 노드 버전

int isEmpty(DListType *DL){
    return DL->size == 0;//logical  0 or 1
}


int isFull(DListType *DL){
    return DL->size == N;//logical  0 or 1
}



void insertFirst(DListType *DL, int g, element e) {
    if (g < 0 || g >= N) {
        printf("Invalid group number: %d\n", g);
        return;
    }

    Node *node = makeNode(e);
    Node *p = DL->H[g];

    node->prev = p;
    node->next = p->next;

    if (p->next != NULL) {
        p->next->prev = node;
    }
    p->next = node;

    DL->size++;
}
// void deleteNode(DListType *DL, Node *p) {
//     if (p == NULL) return;
//     p->prev->next = p->next;
//     p->next->prev = p->prev; 
//     free(p); // 현재 노드 메모리 해제
//     DL->size--;
// }
// element deletegroup(DListType *DL,group g) {
//     Node *p = DL->H->next; 
//     while(p != DL->T) {
//         if (p->group == g ) {
//             element e = p->data;
//             deleteNode(DL, p);
//             printf("%c is deleted.\n\n", g);
//             return e;
//         }
//         p = p->next;
//     }
//     printf("not found\n");
// }

void print(DListType *DL) {
    /*
    for(int i = 0; i < DL->size; i++){
        printf("%c ", p->data);
        p = p->next;
    }
    */
    for(int i = 0; i < N; i++){
        for(Node *p = DL->H[i]->next;p!=DL->T[i];p=p->next){
            printf("%c ",p->data);
        }
        printf("\n");
    }
}

int main() {
    DListType Dlist;
    init(&Dlist);
    srand(time(NULL));
    
    for(int i = 0; i < 10; i++){
        element e = rand() % 26 + 65; // 65~90
        int g = rand() % 100 ; 
        insertFirst(&Dlist,g,e);
    }
    
    print(&Dlist);
    // deletegroup(&Dlist,'D');
    // print(&Dlist);
}