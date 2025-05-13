#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

#define N 101

typedef double element;

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

int member(StackType *S, char ch){
    Node *p = S->top;
    while(p != NULL){
        if(p->data == ch) return 1;
        p = p->next;
    }
    return 0;
}
int isOperator(char ch){
    return (ch == '+' || ch == '-' 
        || ch == '*'  || ch == '/');
}
double evaluate(StackType *Postfix){
    StackType S;
    Init(&S);
    double op1, op2, result;
    char ch;
    int n = Postfix->size;
    for(int i=0;i<n;i++){
        ch = Pop(Postfix);
        if(ch >= 0 && ch <= 9){
            Push(&S, ch);
        }
        else if(isOperator(ch)){
            op2 = Pop(&S);
            op1 = Pop(&S);
            switch(ch){
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = (double)op1 / op2; break;
            }
            Push(&S, result);
        }
    }
    return Pop(&S);
}

int main(void){
    StackType S;
    Init(&S);
    char postfix[N];
    int n=0;
    scanf("%d",&n);
    getchar();
    fgets(postfix,N,stdin);
    for(int i=0;i<strlen(postfix);i++){
        Push(&S, postfix[i]);
    }
    
    int tmp=0;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if (member(&S, 'A' + i)){
            S.top->data = tmp;
        }
        
    }
    double value = evaluate(&S);
    printf("%.2lf", value);
    return 0;
}
