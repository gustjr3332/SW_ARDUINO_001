#pragma warning disable C4996
#include <stdio.h>
#include <stdlib.h>

#define N 100
//헤더 노드 버전

typedef char element;

typedef struct Node {
    element data;
    struct Node *prev; 
    struct Node *next;
} Node;

typedef struct DListType {
    Node *head; // 헤더 노드
    Node *tail; // 꼬리 노드
    int size;   // 리스트 크기
} DListType;


void init(DListType *DL) {
    DL->head = (Node *)malloc(sizeof(Node));
    DL->head->next = DL->tail;
    DL->head->prev = NULL;
    DL->tail = (Node *)malloc(sizeof(Node));  
    DL->tail->prev = DL->head;
    DL->tail->next = NULL; 

    DL->size = 0;                           
}//헤드 노드,테일 노드 버전

int isEmpty(DListType *DL){
    return DL->size == 0;//logical  0 or 1
}


int isFull(DListType *DL){
    return DL->size == N;//logical  0 or 1
}

// 노드 생성
Node *makeNode(element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->prev = NULL; 
    node->next = NULL;
    return node;
}

void insert(DListType *DL, int pos, element e) {
    if (pos <= 0 || pos > DL->size + 1) {
        printf("insertion error\n");
        return;
    }

    Node *node = makeNode(e);
    Node *p = DL->head; 

    for (int i = 1; i < pos; i++) {
        p = p->next;
    }
    node->next = p->next;
    p->next->prev = node; 

    node->prev = p;
    p->next = node;

    DL->size++;
    //DL->head->prev = DL->tail->prev;
    //DL->tail->next = DL->head->next;
    //원현연결 추가
}

element delete(DListType *DL, int pos) {
    if (pos <= 0 || pos > DL->size) {
        printf("deletion error\n");
        return -1;
    }

    Node *p = DL->head; // 헤더 노드부터 시작
    Node *q = NULL;

    for (int i = 1; i < pos; i++) {
    p = p->next;
    }

    q = p->next;
    element e = q->data;
    p->next = q->next;
    free(q);
    DL->size--;
    return e;
}

void print(DListType *DL) {
    Node *p = DL->head->next; //헤더 노드 다음 노드부터 시작
    for(int i = 0; i < DL->size; i++){
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    DListType Dlist;
    init(&Dlist);
    int n=0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char type;
        getchar();
        scanf("%c", &type);
        if(type == 'A'){
            int pos=0;
            char data;
            scanf("%d %c", &pos, &data);
            add(&Dlist, pos, data);
        }
        else if(type == 'D'){
            int pos=0;
            scanf("%d", &pos);
            delete(&Dlist, pos);
        }
        else if(type == 'G'){
            int pos=0;
            scanf("%d", &pos);
            get(&Dlist, pos)== -1 ? printf("invalid position\n") 
            : printf("%c\n", get(&Dlist, pos));
        }
        else if(type == 'P'){
            print(&Dlist);
        }
    }
    return 0;
}


//completed
/*
//double linked list
typedef char element;

typedef struct Node {
    element data;
    struct Node *prev; 
    struct Node *next;
} Node;

typedef struct DListType {
    Node *head; // 헤더 노드
    Node *tail; // 꼬리 노드
    int size;   // 리스트 크기
} DListType;

// 헤더 노드 초기화
void init(DListType *DL) {
    DL->head = NULL; 
    //DL->head->next = Dl->tail; 
    DL->tail = NULL;  
    //DL->tail->prev = DL->head;                
    DL->size = 0;                           
}

int isEmpty(DListType *DL){
    //return L->head == NULL;
    return DL->size == 0;//logical  0 or 1
}


int isFull(DListType *DL){
    return DL->size == N;//logical  0 or 1
}

// 노드 생성
Node *makeNode(element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->prev = NULL; 
    node->next = NULL;
    return node;
}

void insertFirst(DListType *DL, element e){
    Node *node = makeNode(e);
    Node* p = DL->head;
    if (p == NULL) {
        DL->head = DL->tail = node;
    }
    else{
        node->next = DL->head;
        DL->head->prev = node;
        DL->head = node;
    }
    DL->size++;
}

void insertLast(DListType *DL, element e){
    Node *node = makeNode(e);
    Node* p = DL->tail;
    if (p == NULL) {
        DL->head = DL->tail = node;
    }
    else{
        node->prev = DL->tail;
        DL->tail->next = node;
        DL->tail = node;
    }
    DL->size++;
}

// 리스트에 요소 삽입
void insert(DListType *DL, int pos, element e) {
    if (pos <= 0 || pos > DL->size + 1) {
        printf("insertion error\n");
        return;
    }

    Node *node = makeNode(e);
    Node *p = DL->head; 

    if(pos == 1) {
        insertFirst(DL, e);
        return;
    }
    else if(pos == DL->size + 1) {
        insertLast(DL, e);
        return;
    }
    else{
    for (int i = 1; i < pos; i++) {
        p = p->next;
    }
    node->next = p->next;
    p->next->prev = node; 
    node->prev = p;
    p->next = node;
    DL->size++;
    }
    
}

element deleteFirst(DListType *DL){
    if(isEmpty(DL)){
        printf("empty\n");
        return -1;
    }
    Node *temp = DL->head;
    element e = temp->data;
    if(DL->head){
        DL->head = temp->next;
        temp->next->prev = NULL; // 두번째 노드의 prev를 NULL로 설정
    }
    else{
        DL->head = DL->tail = NULL; 
    }
    free(temp);
    DL->size--;
    return e;
}
element deleteLast(DListType *DL){
    if(isEmpty(DL)){
        printf("empty\n");
        return -1;
    }
    Node *temp = DL->tail;
    element e = temp->data;
    if(DL->tail){
        DL->tail = temp->prev;
        temp->prev->next = NULL; // 마지막 노드의 prev를 NULL로 설정
    }
    else{
        DL->head = DL->tail = NULL; 
    }
    free(temp);
    DL->size--;
    return e;
}
element delete(DListType *DL, int pos) {
    if (pos <= 0 || pos > DL->size) {
        printf("deletion error\n");
        return -1;
    }

    Node *p = DL->head; // 헤더 노드부터 시작
    Node *q = NULL;

    if(pos == 1) return deleteFirst(DL);
    else if(pos == DL->size) return deleteLast(DL);
    else{
        for (int i = 2; i < pos; i++) {
        p = p->next;
    }

    q = p->next;
    element e = q->data;
    p->next = q->next;
    free(q);
    DL->size--;
    return e;
    }
}

// 리스트 출력
void print(DListType *DL) {
    Node *p = DL->head; 
    for(int i = 0; i < DL->size; i++){
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main() {
    DListType Dlist;
    init(&Dlist);

    insertFirst(&Dlist, 'B');
    insertFirst(&Dlist, 'A');
    insertLast(&Dlist, 'E');
    insert(&Dlist, 2, 'C');
    insert(&Dlist, 3, 'D');
    print(&Dlist);
    printf("%c is deleted.\n", deleteFirst(&Dlist));
    print(&Dlist);
    printf("%c is deleted.\n", deleteLast(&Dlist));
    print(&Dlist);
    printf("%c is deleted.\n", delete(&Dlist, 2));
    print(&Dlist);

    return 0;
}
*/