//FIFO FirsT in First out
#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

#define N 10
typedef int element;
typedef struct QueueType{
    element data[N];
    int front, rear;
}QueueType;
void Init(QueueType *Q){
    Q->front = Q->rear = -1;
}
//
void Init(QueueType *Q){
    Q->front = Q->rear = 0;
}
int IsFull(QueueType *Q){
    return (Q->rear + 1) % N == 0;
}
//circular queue
int IsEmpty(QueueType *Q){
    return Q->front == Q->rear;
}
int IsFull(QueueType *Q){
    return Q->rear== N-1;
}

void Enqueue(QueueType *Q, element e){
    if(IsFull(Q)){
        printf("overflow\n");
    }
    else{
    Q->rear ++;
    Q->data[Q->rear] = e;
    }
}

element Dequeue(QueueType *Q){
    if(IsEmpty(Q)){
        printf("underflow\n");
        return -1;
    }
    Q->front ++;
    return Q->data[Q->front];
}
element Peek(QueueType *Q){
    if(IsEmpty(Q)){
        printf("underflow\n");
        return -1;
    }
    return Q->data[Q->front+1];
}
void Print(QueueType *Q){
    if(IsEmpty(Q)) printf("NAN\n");
    else printf("Queue: ");
    for(int i = Q->front+1; i <= Q->rear; i++){
        printf(" %d", Q->data[i]);
    }
    printf("\n");
}

int main(void){
    QueueType Q;
    Init(&Q);
    srand(time(NULL));
    for(int i = 0; i < 7; i++){
        Enqueue(&Q, rand()%10+1);
    }
    Print(&Q);
    for(int i = 0; i < 3; i++){
    printf("Dequeue: %d\n", Dequeue(&Q));
    }
    Print(&Q);
    printf("Peek: %d\n", Peek(&Q));
    return 0;
}