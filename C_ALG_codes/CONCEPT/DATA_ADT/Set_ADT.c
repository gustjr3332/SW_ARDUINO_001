#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>


//헤더 포인터 단일 연결 리스트 사용한
//집합 기본 함수들 메모
Node* Union(SetType *A, SetType *B){
    Node *p = A->head;
    Node *q = B->head;
    //SetType *C;
    //init(C);
    //**중요한 오류 -> 포인터 C 초기화 X->init함수 작동X
    SetType *C=malloc(sizeof(SetType));
    init(C);
    //따라서 리스트 자체에 대한 동적할당 진행
    while(p != NULL && q != NULL){
        if(p->data < q->data){
            insert(C, C->size+1, p->data);
            //C.addLast
            p = p->next;
        }
        else if(p->data > q->data){
            insert(C, C->size+1, q->data);
            q = q->next;
        }
        else{
            insert(C, C->size+1, p->data);
            p = p->next;
            q = q->next;
        }
    }
    while(p != NULL){
        insert(C, C->size+1, p->data);
        p = p->next;
    }
    while(q != NULL){
        insert(C, C->size+1, q->data);
        q = q->next;
    }
    return C;
}
Node* Intersect(SetType *A, SetType *B){
    Node *p = A->head;
    Node *q = B->head;
    SetType *C=malloc(sizeof(SetType));
    init(C);
    while(p != NULL && q != NULL){
        if(p->data < q->data){
            p = p->next;
        }
        else if(p->data > q->data){
            q = q->next;
        }
        else{
            insert(C, C->size+1, p->data);
            p = p->next;
            q = q->next;
        }
    }
    return C;
}
int Member(SetType *A, int e){
    Node *p = A->head;
    while(p != NULL){
        if(p->data == e) return 1;
        p = p->next;
    }
    return 0;
}
Node* Subset(SetType *A, SetType *B){
    Node *p = A->head;
    Node *q = B->head;
    if(isEmpty(A)) return p;
    while(p != NULL){
        if(Member(B, p->data)==0) {
            return p->data;
        }
        else p= p->next;
    }
    //member 먼저 검사 후 재호출
    return 0;
}


typedef int element;

typedef struct Node{
    element data;
    struct Node *next; 
}Node;

#define N 100

typedef struct SetType{
    Node *head;
    int size;
}SetType;
//리스트 메이커

void init(SetType *L){
    L->head = NULL;
    L->size = 0;
}
//리스트 초기화

int isEmpty(SetType *L){
    return L->size == 0;//logical  0 or 1
}
//리스트가 비어있는지 확인

int isFull(SetType *L){
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

void insertFirst(SetType *L, element e){
    Node *node = makeNode(e);
    node->next = L->head;
    L->head = node;
    L->size++;
}
//리스트에 첫번째요소 삽입
void insert(SetType *L,int pos,element e){
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
        
        L->size++;
    }
}
//리스트에서 요소 삽입

element deleteFirst(SetType *L){
    if(isEmpty(L)){
        printf("empty\n");
        return -1;
    }
    Node *temp = L->head;
    element e = temp->data;
    L->head = temp->next;
    free(temp);
    L->size--;
    return e;
}

element delete(SetType *L,int pos){
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
}//리스트에서 요소 삭제

void print(SetType *L){
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

    SetType *A;
    SetType *B;
    init(A);
    init(B);
    int n1=0,n2=0;
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++){
        int num=0;
        scanf("%d", &num);
        insert(A, i, num);
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++){
        int num=0;
        scanf("%d", &num);
        insert(B, i, num);
    }

    return 0;
}

