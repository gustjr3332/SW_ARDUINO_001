#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>


/* 의사코드 (하노이탑 횟수)
ALG hanoi(n)
    input positive integer n
    output moving count k
1.if(n=1)return 1
    else return 2 * hanoi(n-1)+1
*/
//n개의 원반이 있을 때 n-1개의 원반을 a->b 옮기고 == n-1 번
//남은 1개를 a->c 옮김 == 1번
//b에 있는 n-1 개를 b->c 옮김 == n-1 번
//따라서 총 횟수 = 2*(n-1)+1 번


/*의사코드 (하노이탑 수행과정) // move(출력 함수 사용)
move(start,end)

ALG hanoi_process(n,start,end,sub)
    input positive integer n
    output process of hanoi by integer n

    1.if(n=1)return move(start,end)
    else return hanoi_process(n-1,start,end,sub)
                print_move(start,end)
                hanoi_process(n-1,sub,end,start)
*/

void move(int start,int end);
int hanoi(int n);
void hanoi_process(int n,int start,int end,int sub);

int main(void){
    int n=0;
    int start=1,end=3,sub=2;
    scanf("%d",&n);
    printf("%d\n",hanoi(n));
    hanoi_process(n,start,end,sub);
    return 0;
}

int hanoi(int n){
    if(n==1)return 1;
    else return 2* hanoi(n-1)+1;
}

void move(int start,int end){
    printf("%d %d\n",start,end);
}
void hanoi_process(int n,int start,int end,int sub){
    if(n==1) move(start,end);
    else {
    hanoi_process(n-1,start,sub,end); //n-1개의 원반을 c를 거쳐 a->b 옮기
    move(start,end); //남은 1개를 a->c 옮김
    hanoi_process(n-1,sub,end,start); //b에 있는 n-1 개를 a를 거쳐 b->c 옮김
    }
}
