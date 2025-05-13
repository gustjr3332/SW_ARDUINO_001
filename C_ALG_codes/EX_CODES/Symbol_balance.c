#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

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
        return -1;
    }
    S->top--;
    return S->data[S->top+1];
}//Stack First Out

int isOpensymbol(char c){
    if(c == '(' || c == '[' || c == '{') return 1;
    return 0;
}
int isClosesymbol(char c){
    if(c == ')' || c == ']' || c == '}') return 1;
    return 0;
}
void isBalanced(char *str){
    if (str == NULL) {
        printf("Wrong_0");
        return;
    }

    StackType S;
    Init(&S);
    int cnt=0;

    for(int i = 0; i < strlen(str); i++) {
        if(isOpensymbol(str[i]) 
        || isClosesymbol(str[i]))cnt++;
    }//그냥 먼저 따로 계산..

    for(int i = 0; i < strlen(str); i++){
        if(isOpensymbol(str[i])) {
            Push(&S, str[i]);
        }
        else if(isClosesymbol(str[i])){
            if(IsEmpty(&S)){
                printf("Wrong_%d",cnt);
                return;
            }
            else{
                char tmp = Pop(&S);
                if((tmp == '(' && str[i] != ')') || 
                (tmp == '[' && str[i] != ']') || 
                (tmp == '{' && str[i] != '}')){
                    printf("Wrong_%d",cnt);
                    return;
                }
            }
        }
    }
    if(IsEmpty(&S)) printf("OK_%d",cnt);
    else printf("Wrong_%d",cnt);
    
}

int main(void){
    char str[1001];
    fgets(str,1001,stdin);
    isBalanced(str);
    return 0;
}
