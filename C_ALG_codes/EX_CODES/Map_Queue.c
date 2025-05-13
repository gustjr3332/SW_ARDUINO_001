#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>


#define N 6

char map[N][N] = {
    {'1','1','1','1','1','1'},
    {'0','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};


typedef struct {
    int r,c;
}Coor;
typedef Coor element;

typedef struct QueueType{
    element data[N];
    int front, rear;
}QueueType;

void Init(QueueType *Q){
    Q->front = Q->rear = 0;
}

int IsFull(QueueType *Q){
    return (Q->rear + 1) % N == Q->front;
}
int IsEmpty(QueueType *Q){
    return Q->front == Q->rear;
}

void Enqueue(QueueType *Q, element e){
    if(IsFull(Q)){
        printf("overflow\n");
    }
    else{
    Q->rear = (Q->rear + 1) % N;
    Q->data[Q->rear] = e;
    }
}

element Dequeue(QueueType *Q){
    if(IsEmpty(Q)){
        printf("underflow\n");
        exit(0);
    }
    Q->front = (Q->front + 1) % N;
    return Q->data[Q->front];
}
element Peek(QueueType *Q){
    if(IsEmpty(Q)){
        printf("underflow\n");
        exit(0);
    }
    return Q->data[Q->front+1];
}
void Print(QueueType *Q){
    if(IsEmpty(Q)) printf("NAN\n");
    int i = Q->front;
    while(i != Q->rear){
        i = (i + 1) % N;
        printf(" (%d,%d)", Q->data[i].r, Q->data[i].c);
    }
    printf("\n");
}
void insertPos(QueueType *Q, int r, int c){
    if(r<0 || c<0 || r>=N || c>=N) return;
    if(map[r][c] != '0' && map[r][c] != 'x') return;
    element pos = {r,c};
    Enqueue(Q, pos);
}
void BFS(QueueType *Q, int r, int c){
    while(!IsEmpty(Q)){
        element pos = Dequeue(Q);
        int r = pos.r;
        int c = pos.c;
        printf("(%d,%d) ", r, c);
        if(map[r][c] == 'x'){
            printf("success.\n");
            return;
        }
        else{
            map[r][c] = '.'; // visited
            insertPos(Q, r-1, c); // up
            insertPos(Q, r+1, c); // down
            insertPos(Q, r, c-1); // left
            insertPos(Q, r, c+1); // right
        }
        Print(Q);
    }
    return;
}
int main(void){
    QueueType Q;
    Init(&Q);
    insertPos(&Q, 1, 0); // start position
    BFS(&Q, 1, 0);
    return 0;
}