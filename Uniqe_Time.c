#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(){
    int sum=0;
    int a,x,y;
    while(1){
    scanf("%d/%d %d분",&x,&y,&a);
    if(x==0) {
        printf("%d시간 %d분입니다!", sum/60, sum%60);
        break;
    }
    sum+=a;
    printf("%d\n",sum);
    }
}
