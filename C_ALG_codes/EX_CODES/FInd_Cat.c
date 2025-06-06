#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

//5���� �����̰� �ִ�. 
//�ƹ�Ű�� ������ �������� ������ �̱�
//5���� ��� �����ؼ� ������ Ű������
//�����̴� �̸�, ����, ����, Ű��� ���̵�(����)�� ������ �ִ�.

typedef struct {
	const char* name;
	int age;
	const char* character;
	int level;//���̵� 1~5 5�� ���� �����
}CAT; //������ struct

int collectcat[5] = { 0,0,0,0,0 }; //���� ���� ������ 0����
CAT cats[5]; //��ü������ ����Ʈ
void initCats();
void printCat(int select);
int check_cat();


int cat_main(void) {
	srand(time(NULL));//���� ���� �̱�
	initCats();
	while (1) {
		printf("��� �������� ���簡 �ɱ��?\n�ƹ�Ű�� ������ Ȯ���ϼ���\n");
		
		getchar(); //���� ���� �̱�

		int select = rand() % 5;//0~4 �������� ��ȯ

		printCat(select);//���� ������ ���� ��� �Լ�

		collectcat[select] = 1;//������ ���� �Ϸ� ó��

		check_cat(); //��� �����̸� �� ��Ҵ��� Ȯ��

		int collectAll = check_cat();

		if (collectAll == 1) {
			printf("!!!��� �����̸� �� ��Ҿ�� ������ Ű���ּ���!!!\n");
			break;
		}
		else continue;

	}
	return 0;
}
void initCats() {
	cats[0].name = "�ϳ���";
	cats[0].age = 3;
	cats[0].character = "�¼�";
	cats[0].level = 1;

	cats[1].name = "�̳���";
	cats[1].age = 2;
	cats[1].character = "��ī�ο�";
	cats[1].level = 4;

	cats[2].name = "�����";
	cats[2].age = 1;
	cats[2].character = "������";
	cats[2].level = 2;

	cats[3].name = "�����";
	cats[3].age = 5;
	cats[3].character = "������";
	cats[3].level = 3;

	cats[4].name = "������";
	cats[4].age = 7;
	cats[4].character = "��ĥ��";
	cats[4].level = 5;
} //������ ���� ���� 

void printCat(int select) {
	printf("--------%d��° ������ ����--------\n", select + 1);
	printf("�̸� : %s\n", cats[select].name);
	printf("���� : %d\n", cats[select].age);
	printf("���� : %s\n", cats[select].character);
	printf("���̵� : ");
	for (int i = 0; i < cats[select].level; i++) {
		printf("%s","��");
	}
	printf("\n\n\n");

}//���� ������ ���� ��� �Լ�

int check_cat() {
	int collectAll = 1;//�� �̾����� ����

	for (int i = 0; i < 5; i++) {
		if (collectcat[i] == 0) {
			collectAll = 0;
		}
	}
	return collectAll;
}//��� �����̸� �� ��Ҵ��� Ȯ�� �Լ�
