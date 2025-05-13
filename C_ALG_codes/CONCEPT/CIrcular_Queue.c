#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

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

void Print(QueueType *Q) {
    for(int i = 0; i < Q->size; i++) {
        if((i > Q->front && i <= Q->rear) || 
        (Q->rear < Q->front && (i > Q->front || i <= Q->rear))) {
         printf(" %d", Q->data[i]);
        }
        else {
            // 빈 공간은 0으로 출력
            printf(" 0");
        }
    }
    printf("\n");
}

int main(void){
    
    int q;
    scanf("%d", &q);
    QueueType Q;
    Init(&Q,q);
    
    int n,elem;
    char type;
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++){
        type = getchar();
        switch(type){
            case 'I':
                if(IsFull(&Q)){ 
                    printf("overflow");
                    Print(&Q);
                    return 0;
                }
                scanf("%d\n", &elem);
                Enqueue(&Q, elem);
                break;

            case 'D':
                if(IsEmpty(&Q)){
                    printf("underflow");
                    return 0;
                }
                Dequeue(&Q);
                getchar();
                break;

            case 'P':
                Print(&Q);
                getchar();
                break;
        }
         
    }
    free(Q.data);
    return 0;
}