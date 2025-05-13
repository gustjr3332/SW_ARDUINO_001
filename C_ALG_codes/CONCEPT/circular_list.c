#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

#define N 100 


//헤드 노드 버전

typedef char element;

typedef struct Node {
    element data;
    struct Node *next;
} Node;

typedef struct ListType {
    Node *tail; // 꼬리 노드
    int size;   // 리스트 크기
} ListType;

// 헤더 노드 초기화
void init(ListType *L) {
    L->tail = (Node *)malloc(sizeof(Node)); //테일 노드 생성
    L->tail->next=NULL;           // 꼬리 노드를 NULL로 초기화
    L->size = 0;               // 리스트 크기 초기화
}

// 노드 생성
Node *makeNode(element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

int isEmpty(ListType *L){
    //return L->head == NULL;
    return L->size == 0;//logical  0 or 1
}
//리스트가 비어있는지 확인

int isFull(ListType *L){

    return L->size == N;//logical  0 or 1
}
//리스트가 꽉 차있는지 확인

void insert(ListType *L, int pos, element e){
    
}

// 리스트 출력
void print(ListType *L) {
    Node *p = L->tail; // 꼬리 노드로 설정
    if(!isEmpty(L)) {
        do
        {
            printf("%c", p->next->data); //첫번째 노드 출력력
            p = p->next; // 다음 노드로 이동
        } while (p != L->tail); // 꼬리 노드까지 반복
            
        
    }
    
    printf("\n");
}

int main() {
    ListType list;
    init(&list);

    insertFirst(&list,'B');
    insertFirst(&list,'A');
   
    print(&list);
    insertLast(&list,'C');
    insertLast(&list,'D');
    print(&list);
    insertFirst(&list,'0');
    print(&list);
    printf("%c is deleted.\n",deleteFirst(&list));
    print(&list);
    deleteLast(&list);
    print(&list);
    return 0;
}

/*
typedef char element;

typedef struct Node {
    element data;
    struct Node *next;
} Node;

typedef struct ListType {
    Node *tail; // 꼬리 노드
    int size;   // 리스트 크기
} ListType;

// 헤더 노드 초기화
void init(ListType *L) {
    L->tail = NULL;             // 꼬리 노드를 NULL로 초기화
    L->size = 0;               // 리스트 크기 초기화
}

// 노드 생성
Node *makeNode(element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

int isEmpty(ListType *L){
    //return L->head == NULL;
    return L->size == 0;//logical  0 or 1
}
//리스트가 비어있는지 확인

int isFull(ListType *L){

    return L->size == N;//logical  0 or 1
}
//리스트가 꽉 차있는지 확인

void insertLast(ListType *L, element e) {
    Node *node = makeNode(e);
    if(isEmpty(L)) {
        L->tail = node; // 리스트가 비어있으면 꼬리 노드에 새로운 노드를 설정
        node->next = node; // 자기 자신을 가리키게 함 (원형 연결)
    } 
    else {
        node->next = L->tail->next; // 새로운 노드가 헤더 노드를 가리키게 함
        L->tail->next = node;       // 첫번째 노드가 새로운 노드를 가리키게 함
        L->tail = node;            // 새로운 노드를 꼬리 노드로 설정
    }
    L->size++;
}

void insertFirst(ListType *L, element e) {
    Node *node = makeNode(e);
    if(isEmpty(L)) {
        L->tail = node; // 리스트가 비어있으면 꼬리 노드에 새로운 노드를 설정
        node->next = node; // 자기 자신을 가리키게 함 (원형 연결)
    } 
    else {
        node->next = L->tail->next; // 새로운 노드가 헤더 노드를 가리키게 함
        L->tail->next = node;       // 첫번째 노드가 새로운 노드를 가리키게 함
       
    }
    L->size++;
}

// 리스트에서 요소 삭제
element deleteFirst(ListType *L) {
   if(isEmpty(L)) return -1;
    Node *q = L->tail->next; // 첫번째 노드
    Node *p = L->tail; // 꼬리 노드
    //Node *q = p->next; // 첫번째 노드 (같은말)
    if(L->size == 1) { //if(p==q) = if(size==1)
        L->tail = NULL; // 값을 없앤 후 남은 주소 널 처리
    } 
    else {
        p->next = q->next; // 꼬리 노드가 첫번째 노드의 다음 노드를 가리키게 함
    }
    element e = q->data; 
    L->size--;
    free(q); // 첫번째 노드 메모리 해제
    return e; 
}

element deleteLast(ListType *L) {
   if(isEmpty(L)) return -1;
    Node *q = L->tail->next; // 첫번째 노드
    Node *p = L->tail; // 꼬리 노드
    //Node *q = p->next; // 첫번째 노드 (같은말)

    if(L->size == 1) { //if(p==q) = if(size==1)
        L->tail = NULL; // 값을 없앤 후 남은 주소 널 처리
    } 
    else {  
        Node *temp = q; // 첫번째 노드
        while(temp->next != L->tail) { 
            temp = temp->next; // 꼬리 노드 전노드 찾기
        }
        temp->next = q; 
        L->tail = temp; 
    }

    element e = p->data; 
    L->size--;
    free(p); // 마지막 노드 메모리 해제
    return e; 
}

// 리스트 출력
void print(ListType *L) {
    Node *p = L->tail; // 꼬리 노드로 설정
    if(!isEmpty(L)) {
        do
        {
            printf("%c", p->next->data); //첫번째 노드 출력력
            p = p->next; // 다음 노드로 이동
        } while (p != L->tail); // 꼬리 노드까지 반복
            
        
    }
    
    printf("\n");
}

int main() {
    ListType list;
    init(&list);

    insertFirst(&list,'B');
    insertFirst(&list,'A');
   
    print(&list);
    insertLast(&list,'C');
    insertLast(&list,'D');
    print(&list);
    insertFirst(&list,'0');
    print(&list);
    printf("%c is deleted.\n",deleteFirst(&list));
    print(&list);
    deleteLast(&list);
    print(&list);
    return 0;
}
*/