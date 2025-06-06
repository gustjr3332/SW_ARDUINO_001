#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

//array ver.Stack ADT
/*
#define N 100
typedef char element;

typedef struct StackType{
    element data[N];
    int top;
}StackType;

void Init(StackType *S){
    S->top = -1;
}
int IsEmpty(StackType *S){
    return S->top == -1;
}
int IsFull(StackType *S){
    return S->top == N-1;
}
void Push(StackType *S, element e){
    if(S->top == N-1){
        printf("Stack is full\n");
        return;
    }
    S->top++;
    S->data[S->top] = e;
}//Stack Last In

element Pop(StackType *S){
    if(S->top == -1){
        printf("Stack is empty\n");
        return;
    }
    S->top--;
    return S->data[S->top+1];
}//Stack First Out

void Print(StackType *S){
    if(IsEmpty(S)) printf("NAN\n");
    else printf("Stack: ");
    for(int i = S->top; i >= 0; i--){
        printf(" %d", S->data[i]);
    }
    printf("\n");
}

int main(void){
    StackType S;
    Init(&S);
    
    return 0;
}
*/
//Array limitations: 100 elements only

//Singly Linked list ver.Stack ADT


typedef char element;

typedef struct Node{
    element data;
    struct Node *next;
}Node;

typedef struct StackType{
    Node *top;
    int size;
}StackType;

void Init(StackType *S){
    S->top = NULL;
    S->size = 0;
}
int IsEmpty(StackType *S){
    return S->top == NULL;
}

Node* makeNode(element e){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    return p;
}

void Push(StackType *S, element e){
    Node *p = makeNode(e);
    p->next = S->top;
    S->top = p;
    S->size++;
}//Stack Last In

element Pop(StackType *S){
    if(IsEmpty(S)){
        printf("Stack is empty\n");
        return -1;
    }
    Node *p = S->top;
    S->top = S->top->next;
    element e = p->data;
    free(p);
    S->size--;
    return e;
}//Stack First Out

void Print(StackType *S){
    Node *p = S->top; //top node
    if(IsEmpty(S)) printf("NAN\n");
    else printf("Stack: ");
    while(p != NULL) {
        printf(" %c", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void){
    StackType S;
    Init(&S);
    Push(&S, 'A');
    Push(&S, 'B');
    Push(&S, 'C');
    Print(&S); // Stack: C B A
    printf("Popped: %c\n", Pop(&S)); // Popped: C
    Print(&S); // Stack: B A
    return 0;
}