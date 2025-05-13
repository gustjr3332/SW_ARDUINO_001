#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#include <stdlib.h>

//파일 입출력   FILE *file = fopen("C:\\파일명","모드");
//fopen 했으면 fclose 필수
//fputs ,fgets == 파일에 문자열 저장
//fprintf ,fscanf == 정형화된 입출력 형식

#define MAX 10000

int main(){
    char line[MAX];

/*  //fputs("데이터 내용",파일 포인터;)
FILE *file1 = fopen("C:\\CODES_vscode\\project1\\.vscode.txt","wb");
if(file==NULL){
    printf("파일 열기 실패\n");
    return 1;
 }
fputs("fputs 이용해 데이터 저장\n",file1);
fclose(file1);
*/

  //fgets(출력할 변수,크기,데이터 받을 파일 포인터)
FILE *file1 = fopen("C:\\CODES_vscode\\project1\\.vscode.txt","rb");

 if(file1==NULL){
    printf("파일 열기 실패\n");
    return 1;
 }
while(fgets(line,MAX,file1) != NULL){
    printf("%s",line);
}


/* fprintf(파일 포인터,"데이터 내용",변수 내용);
FILE *file2 = fopen("C:\\CODES_vscode\\project1\\.vscode.txt2","wb");
if(file2 == NULL){
    printf("파일 열기 실패\n");
    return 1;
}
fprintf(file2, "%d %d %d %s\n" ,1,2,3,"시작합니다");

fclose(file2);
*/

char str[MAX];
int num[MAX];
  //fscanf(파일 포인터,"데이터 내용",변수수내용)
FILE *file2 = fopen("C:\\CODES_vscode\\project1\\.vscode.txt2","rb");
if(file2 == NULL){
    printf("파일 열기 실패\n");
    return 1;
}

fscanf(file2,"%d %d %d %s",&num[0],&num[1],&num[2],str);
printf("%d %d %d\n%s",num[0],num[1],num[2],str);
fclose(file2);


}
