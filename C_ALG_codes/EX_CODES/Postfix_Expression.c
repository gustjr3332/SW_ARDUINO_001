#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

#define N 101

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

int isOperator(char ch){
    return (ch == '+' || ch == '-' 
        || ch == '*'  || ch == '/'
        || ch == '!'  || ch =='>'
        || ch == '<' || ch == '&' 
        || ch == '|'|| ch == 'p' || ch == 'm');
}

int isUnaryOperator(char op, char prev) {
   
    int isUnaryOp = (op == '!' || op == '+' || op == '-');
    
    int isValidPosition = (prev == '\0' ||prev == '(' ||isOperator(prev));
                          
    return isUnaryOp && isValidPosition;
}//확인용 함수

int prec(char op, char prev) {
    if(isUnaryOperator(op, prev)) {
                return 6; 
    }
    else{
    switch(op){
        case 'p': case 'm': case '!':
            return 6; 
        case '+': case '-': 
            return 4;
        case '*': case '/':
            return 5;
        case '>': case '<': 
            return 3;
        case '&':
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
    }
}

void convert(char *infix, char *postfix){
    StackType S;
    Init(&S);
    int n = strlen(infix);
    int j = 0;
    char ch, top_op;
    char prev = '\0';

    for (int i = 0; i < n; i++) {
        ch = infix[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            Push(&S, ch);
        } 
        else if (ch == ')') {
            while (!IsEmpty(&S)) {
                top_op = Pop(&S);
                if (top_op == '(') break;
                if (top_op == '&' || top_op == '|') {
                    postfix[j++] = top_op;
                    postfix[j++] = top_op;
                } else {
                    postfix[j++] = top_op;
                }
            }
        } 
        else {

            if(isUnaryOperator(ch, prev)) {
                if(ch == 'p' || ch == 'm') {
                    postfix[j++] = ch;
                } 
                else{
                    while (!IsEmpty(&S) && (prec(S.top->data, prev) > prec(ch, prev))) {
                        top_op = Pop(&S);
                        if(top_op == '&' || top_op == '|') {
                            postfix[j++] = top_op;  
                            postfix[j++] = top_op; //두번 작성
                        } else {
                            postfix[j++] = top_op;
                        }
                    }
                    char value ;
                    switch (ch){
                    case '+':
                        value = 'p';
                        break;
                    case '-':
                        value = 'm';
                        break;
                    default:
                        value = ch;
                        break;
                    }
                    Push(&S, value); 
                }
            }

            else if((ch == '&' || ch == '|') && infix[i+1] == ch) {
                    while(!IsEmpty(&S) && prec(S.top->data, prev) >= prec(ch, prev)) {
                        top_op = Pop(&S);
                        if(top_op == '&' || top_op == '|') {
                            postfix[j++] = top_op;  
                            postfix[j++] = top_op; //두번 작성
                        } else {
                            postfix[j++] = top_op;
                        }
                    }
                    Push(&S, ch); //저장은 & ,| 한개만
                    i++;  // 다음 문자 건너뛰기
                }
            
            else {
                while (!IsEmpty(&S) && (prec(S.top->data, prev) >= prec(ch, prev))) {
                    top_op = Pop(&S);
                    if(top_op == '&' || top_op == '|') {
                        postfix[j++] = top_op;  
                        postfix[j++] = top_op; //두번 작성
                    } else {
                        postfix[j++] = top_op;
                    }
                }
                Push(&S, ch);
            }
            
        }
        prev = ch;
    }

    while (!IsEmpty(&S)) {
        top_op = Pop(&S);
        if (top_op == '&' || top_op == '|') {
            postfix[j++] = top_op;
            postfix[j++] = top_op;
        } else {
            postfix[j++] = top_op;
        }
    }
    
    postfix[j] = '\0';

    for(int i=0;i<strlen(postfix);i++){
        if(postfix[i] == 'p'){
            postfix[i] = '+';
        }
        else if(postfix[i] == 'm'){
            postfix[i] = '-';
        }
    }
    return;
}

int main(void){
    char infix[N], postfix[N];
    int n=0;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
    fgets(infix,N,stdin);
    
    convert(infix, postfix);
    printf("%s\n", postfix);
    }
    return 0;
}