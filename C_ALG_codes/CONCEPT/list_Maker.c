//list memo
#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>

#define N 100

typedef int element; 
//int형으로 element 구조체 정의

typedef struct ListType{
    int size;
    element list[N];//size =요소의 갯수 = 빈 첫번째 인덱스스
}ListType;
//리스트 메이커

void init(ListType *L){
    L->size = 0;
}
//리스트 초기화

int isEmpty(ListType *L){
    
    return L->size == 0;//logical  0 or 1
}
//리스트가 비어있는지 확인

int isFull(ListType *L){
    return L->size == N;
}
//리스트가 꽉 차있는지 확인

void insert(ListType *L,int pos,element e){
    if(!isFull(L) && (pos >= 0) && (pos <= L->size)){
        for(int i = (L->size-1); i >= pos; i--){
            L->list[i+1] = L->list[i];
        }
        L->list[pos] = e;
        L->size++;
    }
    else{
        printf("insertion error\n");
    }
}//리스트에서 요소 삽입

void delete(ListType *L, int pos){
    if(!isEmpty(L) && (pos >= 0) && (pos < L->size)){
        for(int i = pos; i < (L->size-1); i++){
            L->list[i] = L->list[i+1];
        }
        L->size--;
    }
    else{
        printf("deletion error\n");
    }
}//리스트에서 요소 삭제

void Get(ListType *L, int pos){
    if(!isEmpty(L) && (pos >= 0) && (pos < L->size)){
        printf("%d\n", L->list[pos]);
    }
    else{
        printf("get error\n");
    }
}//리스트에서 요소 가져오기

void print(ListType *L){
    for(int i = 0; i < L->size; i++){
        printf("%d ", L->list[i]);
    }
    printf("\n");
}//리스트 출력


int main(){
    ListType L;
    init(&L);
    insert(&L, 0, 0);
    insert(&L, 1, 10);
    insert(&L, 2, 20);
    insert(&L, 3, 30);
    delete(&L, 1);
    delete(&L, 6);
    print(&L);


    return 0;
}