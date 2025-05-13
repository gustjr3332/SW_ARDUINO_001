#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>
//희소 다항식

#define n 100

typedef struct Poly {
    int degree;
    int coef[n];
} Poly;

Poly *add(Poly *a, Poly *b){
    Poly *c = (Poly *)malloc(sizeof(Poly)); 
    c->degree = (a->degree > b->degree) ? a->degree : b->degree;
    for(int i=0;i<=c->degree;i++){
        c->coef[i] = ((i<= a->degree) ? a->coef[i]: 0)+((i <= b->degree) ? b->coef[i]: 0);
    }
    
    return c;
}

void print(Poly *p){
    for(int i = p->degree ; i> 0 ; i--){
        printf("%2dx^%d +",p->coef[i],i);
    }
    printf("%d\n",p->coef[0]);
}

int main(void){
    // Poly *a = (Poly *)malloc(sizeof(Poly)); 
    // Poly *b = (Poly *)malloc(sizeof(Poly)); 

    // if (a == NULL || b == NULL) { // 메모리 할당 실패 확인
    //     fprintf(stderr, "Memory allocation failed\n");
    //     return 1;
    // }

    // scanf("%d %d", &(a->degree), &(b->degree)); 

    // for (int i = 0; i <= a->degree; i++) {
    //     scanf("%d", &(a->coef[i]));
    // }
    // for (int i = 0; i <= b->degree; i++) {
    //     scanf("%d", &(b->coef[i]));
    // }

    Poly a,b;
    scanf("%d %d", &a.degree, &b.degree); 
    for (int i = 0; i <= a.degree; i++){
        scanf("%d", &a.coef[i]);
    }
    for (int i = 0; i <= b.degree; i++){
        scanf("%d", &b.coef[i]);
    }

    print(add(&a, &b));


    //free(a); 
    //free(b); 

    return 0;
}
