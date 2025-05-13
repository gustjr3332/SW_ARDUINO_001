//return 0; 에 종단점 설정해서 외부 터미널에서도 출력 값 확인인
/*  

//헤더파일 모음

#include<stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#include<time.h>
#include<stdlib.h>
*/




/*
ctrl k c 전체 주석
ctrl k u  주석 해제
*/




/*  //문제 풀이 시 주의사항

int 형 double 형 등 인수 변환 있을때
변수 여러개 선언하지 말고 계산적으로 풀기
ex)<prefixAverage_alg>
   A1[i] = (int)((double)sum / (i + 1) + 0.5);

//문자열 입력 받을 때
문자 한개씩 입력 -> getchar() 사용
문자열 입력 -> scanf("%s", str);

strlen == 시간복잡도 O(n) 따라서 반복문 안에 쓰지 말것;
변수 추가 생성해 사용 ㄱㄱ
*/



/*
((((long) rand() << 15) | rand()) % 1000000) + 1
- 1 ~ 1,000,000 범위의 난수를 생성한다.
srand(time(NULL))//시간이용해 난수 생성
for(int i=0;i<n;i++){
        x[i]=rand() %10000 +1; //난수 들 중 1~10000사이 정수 대입
    }
*/



//입력 받은대로 출력
/*
int main(void) {
    char a[101];

    while(scanf("%[^\n]", a) != EOF) {
        printf("%s\n", a);
        getchar(); // %[^\n]을 사용해 \n이 나올 때까지 입력받고 \n을 버퍼에 남겨두었을 것이므로 제거해준다.
    }

    return 0;
}
*/