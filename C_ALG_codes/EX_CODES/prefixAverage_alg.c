#include<stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#include<stdlib.h>

// int *prefixAverage1(int *x, int n);
// int *prefixAverage2(int *x, int n);


// int main(void){
//     int n=0;
//     scanf("%d", &n);
//     int *x = (int *)malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &x[i]);
//     }

//     for(int i=0; i<n; i++){
//         printf("%d ", *(prefixAverage1(x, n)+i));
//     }
//     printf("\n");
//     for(int i=0; i<n; i++){
//         printf("%d ", *(prefixAverage2(x, n)+i));
//     }
//     return 0;

// }

// int *prefixAverage1(int *x, int n) {
//     int *A1 = (int *)malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++) {
//         int sum = 0;
        
//         for (int j = 0; j <= i; j++) {
//             sum += x[j];
//         }
//         A1[i] = (int)((double)sum / (i + 1) + 0.5);
//     }
//     return A1;
// } //slowprefixAverage alg-->n^2

// int *prefixAverage2(int *x, int n) {
//     int *A2 = (int *)malloc(sizeof(int) * n);
//     int sum = 0;
    
//     for (int i = 0; i < n; i++) {
//         sum += x[i];
//         A2[i] = (int)((double)sum / (i + 1) + 0.5);
//     }  //묶어서 계산하니 출력 결과 ok
//     return A2;
// }//fastprefixAverage alg-->n

#include<time.h>
#include<Windows.h>

int *prefixAverage1(int *x, int n);
int *prefixAverage2(int *x, int n);


int pre_main(void){
    int n=0;
    scanf("%d", &n);
    srand(time(NULL));
    getchar();
    int *x = (int *)malloc(sizeof(int) * n);
    for(int i=0;i<n;i++){
        x[i]=rand() %10000 +1;
    }
    
    LARGE_INTEGER ticksPerSec1;
    LARGE_INTEGER start1, end1, diff1;
    QueryPerformanceFrequency(&ticksPerSec1);
    QueryPerformanceCounter(&start1);
    prefixAverage1(x,n);
    QueryPerformanceCounter(&end1);
    // 측정값으로부터 실행시간 계산
    diff1.QuadPart = end1.QuadPart - start1.QuadPart;
    printf("%.9fms\n", ((double)diff1.QuadPart/(double)ticksPerSec1.QuadPart));
    
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    prefixAverage2(x,n);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("%.9fms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    
    return 0;

}

int *prefixAverage1(int *x, int n) {
    int *A1 = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int j = 0; j <= i; j++) {
            sum += x[j];
        }
        A1[i] = (int)((double)sum / (i + 1) + 0.5);
    }
    return A1;
} //slowprefixAverage alg-->n^2

int *prefixAverage2(int *x, int n) {
    int *A2 = (int *)malloc(sizeof(int) * n);
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += x[i];
        A2[i] = (int)((double)sum / (i + 1) + 0.5);
    }  //묶어서 계산하니 출력 결과 ok
    return A2;
}//fastprefixAverage alg-->n