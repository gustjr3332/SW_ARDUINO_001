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

void DFS(int v){
    visited[v] = TRUE;
    printf("%c ", vName[v]);
    
    for(int i = 0; i < N; i++){
        if(graph[v][i] == 1 && visited[i] == FALSE){
            DFS(i);
        }//adjacency check
         //and if not visited, call DFS recursively
    }
}

typedef int element;
typedef struct QueueType{
    element *data;
    int front, rear;
    int size;
}QueueType;

void Init(QueueType *Q,int size){
    Q->data = (element *)malloc(sizeof(element) * (size));
    Q->size = size;
    Q->front = Q->rear = 0;
}
int IsFull(QueueType *Q){
    return (Q->rear + 1) % Q->size == Q->front;
}

int IsEmpty(QueueType *Q){
    return Q->front == Q->rear;
}

void Enqueue(QueueType *Q, element e){
    if(IsFull(Q)){
        printf("overflow");
        return;
    }

    Q->rear = (Q->rear + 1) % Q->size;
    Q->data[Q->rear] = e;
    
}

element Dequeue(QueueType *Q){
    if(IsEmpty(Q)){
        printf("underflow");
        return -1;
    }
    Q->front = (Q->front + 1) % Q->size;
    return Q->data[Q->front];
}

void BFS(int start){
    QueueType Q;
    Init(&Q, N);

    visited[start] = TRUE;
    Enqueue(&Q, start);

    while(!IsEmpty(&Q)){
        int v = Dequeue(&Q);
        printf("%c ", vName[v]);

        for(int i = 0; i < N; i++){
            if(graph[v][i] == 1 && visited[i] == FALSE){
                visited[i] = TRUE;
                Enqueue(&Q, i);
            }
        }
    }
    free(Q.data);
}

int main(){
    for(int i = 0; i < N; i++){
        visited[i] = FALSE;
    }
    
    printf("DFS Traversal: ");
    DFS(0); // Start DFS from vertex A (index 0)
    printf("\nVisited vertices: \n");
    print();
    
    for(int i = 0; i < N; i++) visited[i] = FALSE;
    

    printf("\nBFS Traversal: ");
    BFS(0);
    printf("\nVisited vertices: \n");
    print();
    
    return 0;
}