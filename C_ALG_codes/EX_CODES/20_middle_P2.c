#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>

void measure(int n,int k);
//재귀 알고리즘 공부
/*
ALg measure(int n,int k)
input a large integer n and a increase integer k
output print a measure of n 

1. if(n < k) return // k가 n보다 크면 종료
   else if(n%k=0) print(k) //약수 출력력

2.measure(n,k+1)
*/

int main(){
    int j=0;
    char s[20];
    char num[20];
    scanf("%s", s);
    int l = strlen(s);
    for(int i = 0; i < l; i++){
        if((s[i] >= '0') && (s[i] <= '9')){
            num[j]=s[i];
            j++;
        }
    }
    int n = atoi(num);

    int k=1;

    while(1){
    if(n%k==0){
        printf("%d ",k);
    }
    k++;
    if(n<k)break;
   }
 //평범 풀이

    measure(n,1);
    
    return 0;
}
void measure(int n,int k){
    if(n<k) return ;
    else if(n%k==0)printf("%d ",k);
    measure(n,k+1);
}

//abc1def2ghi1j
//Aa3Bb6Cc