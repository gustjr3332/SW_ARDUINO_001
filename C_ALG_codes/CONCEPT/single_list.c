/*
#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>



typedef char element;

typedef struct Node{
    element data;
    struct Node *next; //자기 참조 구조체
}Node;

#define N 100
typedef struct ListType{
    Node *head;
    int size;
    element list[N];//size =요소의 갯수 = 빈 첫번째 인덱스
}ListType;
//리스트 메이커

void init(ListType *L){
    L->head = NULL;
    L->size = 0;
}
//리스트 초기화

int isEmpty(ListType *L){
    //return L->head == NULL;
    return L->size == 0;//logical  0 or 1
}
//리스트가 비어있는지 확인

int isFull(ListType *L){

    return L->size == N;//logical  0 or 1
}
//리스트가 꽉 차있는지 확인

Node* makeNode(element e){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    return p;
}
//노드 생성

void insertFirst(ListType *L, element e){
    Node *node = makeNode(e);
    node->next = L->head;//새로운 노드가 헤더를 가리키게 함
    L->head = node;//헤더가 새로운 노드를 가리키게 함
    L->size++;
}
//리스트에 첫번째요소 삽입
void insert(ListType *L,int pos,element e){
    if(pos <= 0 || pos > L->size+1){
        printf("insertion error\n");
        return;
    }
    Node *node = makeNode(e);
    Node*p= L->head;
    if(pos==1)insertFirst(L,e);
    else{
        for(int i = 2; i < pos; i++){
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
        node->prev = p;
        if(node->next != NULL){
            node->next->prev = node;
        }
        L->size++;
    }
}
//리스트에서 요소 삽입
element deleteFirst(ListType *L){
    if(isEmpty(L)){
        printf("empty\n");
        return -1;
    }
    Node *temp = L->head;//첫번째 노드를 가리키는 포인터
    element e = temp->data;//출력할 요소 = 첫번째 노드의 데이터
    L->head = temp->next; //헤더가 두번째 노드를 가리키게 함
    free(temp);//메모리 해제
    L->size--;
    return e;
}
//리스트에서 요소 삭제

element delete(ListType *L,int pos){
    if(pos <= 0 || pos > L->size){
        printf("insertion error\n");
        return -1;
    }
    Node *p = L->head;
    Node *q = NULL;

    if(pos == 1) return deleteFirst(L);
    else{
    for(int i = 2; i <= pos; i++){
        q=p;
        p = p->next;
    }
    element e = p->data;
    q->next = p->next;
    
    free(p);
    L->size--;
    return e;
    }
}

void print(ListType *L){
    Node *p = L->head;
    // while(p != NULL){
    //     printf("%c", p->data);
    //     p = p->next;
    // }
    for(Node *p = L->head; p != NULL; p = p->next){
        printf("%c", p->data); //for문으로 간단하게
    }
    printf("\n");
}
int main(){
    Node *head;

    ListType *L;

    init(L);
    insertFirst(L, 'A');print(L);
    insertFirst(L, 'B');print(L);
    printf("%c is deleted.\n", deleteFirst(L));
    print(L);
    insert(L, 1, 'C');print(L);
    return 0;
}
*/

//헤더 노드 활용 단일연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node {
    element data;
    struct Node *next;
} Node;

typedef struct ListType {
    Node *head; // 헤더 노드
    int size;   // 리스트 크기
} ListType;

// 헤더 노드 초기화
void init(ListType *L) {
    L->head = (Node *)malloc(sizeof(Node)); // 헤더 노드 생성
    L->head->next = NULL;                  // 헤더 노드의 next를 NULL로 초기화
    L->size = 0;                           // 리스트 크기 초기화
}

// 노드 생성
Node *makeNode(element e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

// 리스트에 요소 삽입
void insert(ListType *L, int pos, element e) {
    if (pos <= 0 || pos > L->size + 1) {
        printf("insertion error\n");
        return;
    }

    Node *node = makeNode(e);
    Node *p = L->head; // 헤더 노드부터 시작

    for (int i = 1; i < pos; i++) {
        p = p->next;
    }

    node->next = p->next;
    p->next = node;
    L->size++;
}

// 리스트에서 요소 삭제
element delete(ListType *L, int pos) {
    if (pos <= 0 || pos > L->size) {
        printf("deletion error\n");
        return -1;
    }

    Node *p = L->head; // 헤더 노드부터 시작
    Node *q = NULL;

    for (int i = 1; i < pos; i++) {
        p = p->next;
    }

    q = p->next;
    element e = q->data;
    p->next = q->next;
    free(q);
    L->size--;

    return e;
}

// 리스트 출력
void print(ListType *L) {
    Node *p = L->head->next; // 헤더 노드 다음 노드부터 시작
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    ListType list;
    init(&list);

    insert(&list, 1, 'A');
    insert(&list, 2, 'B');
    insert(&list, 3, 'C');
    print(&list);

    delete(&list, 2);
    print(&list);

    return 0;
}