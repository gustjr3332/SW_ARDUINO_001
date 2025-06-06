#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>


//heap Tree
//완전 이진 트리 기반 (왼쪽부터 가득 차있는 트리)

#define N 20
typedef int element;
typedef struct HeapType{
    element heap[N];
    int heapsize;
}HeapType;
 void init(HeapType *H){
    H->heapsize = 0;
    H->heap[0] = 0;
}
void upHeap(HeapType *H){
    int i = H->heapsize;
    element key = H->heap[i];
    while(i > 1 && key > H->heap[i/2]){
        H->heap[i] = H->heap[i/2];//parent 노드와 교환
        i /= 2;
    }
    H->heap[i] = key;
}
void insertItem(HeapType *H, element item){
    H->heapsize++;
    H->heap[H->heapsize] = item;
    upHeap(H);
}
void downHeap(HeapType *H){
    int parent = 1; int child = 2;//(left child)
    element key = H->heap[1];

    while(child <= H->heapsize){
        
        if(child < H->heapsize && H->heap[child] < H->heap[child + 1]){
            child++;
        }
//right child가 존재할 경우(right child = child + 1)
//right child가 left child보다 클 경우
        if(key >= H->heap[child]) break;
        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }
    H->heap[parent] = key;
}
element deleteItem(HeapType *H){
    if(H->heapsize == 0){
        printf("Heap is empty\n");
        return -1;
    }
    element key = H->heap[1];
    H->heap[1] = H->heap[H->heapsize];
    H->heapsize--;
    downHeap(H);
    return key;
}
int isHeapMax(HeapType *H){
    for(int i = 1; i <= H->heapsize/2; i++){
        if(H->heap[i] < H->heap[i/2]) return 0;
    }
    return 1;
}
void printHeap(HeapType *H){
    for(int i = 1; i <= H->heapsize; i++){
        printf("%d ", H->heap[i]);
    }
    printf("\n");
}
void heapSort(HeapType *H){
    int n = H->heapsize;
    int A[n];
    for(int i = n-1; i >= 0; i--){
        A[i]=deleteItem(H);
    }
    for(int i = 0; i < n; i++){
        printf(" %d", A[i]);
    }
    H->heapsize = n;
}
int main(){
    HeapType H;
    init(&H);
    insertItem(&H, 10);
    insertItem(&H, 20);
    insertItem(&H, 30);
    insertItem(&H, 40);
    insertItem(&H, 50);
    insertItem(&H, 60);
    insertItem(&H, 70);
    insertItem(&H, 80);
    insertItem(&H, 90);
    insertItem(&H, 100);
    printHeap(&H);
    insertItem(&H, 110);
    printHeap(&H);
    deleteItem(&H);
    printHeap(&H);
    heapSort(&H);
    return 0;
}