#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>
//Heap 배열로 기본 생성(알고리즘)
void Heapify(int A[], int i, int len) {
    int max = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left < len && A[left] > A[i]) {
        max = left;
    }
    if(right < len && A[right] > A[max]) {
        max = right;
    }
    if(max != i) {
        int temp = A[i];
        A[i] = A[max];
        A[max] = temp;
        Heapify(A, max, len);
    }
}
//Heapify(A, i, len) : A[i]를 루트로 하는 서브트리를 
//최대 힙으로 만든다.
void buildHeap(int A[], int len) {
    for (int i = len / 2; i >= 1; i--) {
        Heapify(A, i, len);
    }
}
void printHeap(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void Heapsort(int A[], int len) {
    buildHeap(A, len);
    for (int i = len-1; i >= 2; i--) {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        Heapify(A, 1, i);
    }
    printf("Sorted A : ");
    printHeap(A, len);
}
int inMaxHeap(int A[], int len) {
    for(int i=1; i<=len/2; i++){
        if(A[i] < A[2*i] || A[i] < A[2*i+1]){
            return 0;
        }
    }
}

int main(){
    int A[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int len = sizeof(A) / sizeof(int);
    buildHeap(A, len);
    printf(" A : ");
    printHeap(A, len);
    Heapsort(A, len);
    

}