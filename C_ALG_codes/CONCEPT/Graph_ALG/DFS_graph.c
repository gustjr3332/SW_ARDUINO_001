#pragma warning(disable:4996)
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define N 8
#define TRUE 1
#define FALSE 0

char vName[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int visited[N];

int graph[N][N] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
};

void print(){
    for(int i = 0; i < N; i++){
        printf("%c ", vName[i]);
        
        for(int j=0;j<N;j++){
            printf("%d ", graph[i][j]);
        }  
    printf("\n");
    }
}




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

void PrintStack(StackType *S){
    if(IsEmpty(S)) printf("NAN\n");
    else printf("Stack: ");
    for(int i = S->top; i >= 0; i--){
        printf(" %d", S->data[i]);
    }
    printf("\n");
}


void iDFS(int s){
    StackType S;
    Init(&S);
    Push(&S, s);
    visited[s] = TRUE;
    printf("%c ", vName[s]);
    while(!IsEmpty(&S)){
        s= Pop(&S);
        int flag = FALSE;
        for(int i = 0; i < N; i++){
            if(graph[s][i] == 1 && visited[i] == FALSE){
                Push(&S, i); // Push adjacent vertex onto stack
                visited[i] = TRUE; // Mark it as visited
                printf("%c ", vName[i]);
                flag = TRUE;
                break; // Break to process the newly pushed vertex
            }
        }
    }
}

int main(){
    for(int i = 0; i < N; i++){
        visited[i] = FALSE;
    }
    
    printf("DFS Traversal: ");
    iDFS(0); // Start DFS from vertex A (index 0)
    printf("\nVisited vertices: \n");
    print();
    
    for(int i = 0; i < N; i++) visited[i] = FALSE;
    

    printf("\nBFS Traversal: ");
    BFS(0);
    printf("\nVisited vertices: \n");
    print();
    
    return 0;
}