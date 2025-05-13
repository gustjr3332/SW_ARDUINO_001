#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#include<time.h>
#include<stdlib.h>

int mostones(int** A, int n) {
	int i = 0, j = 0, row = 0;

	while ((i < n) && (j < n)) {
		if (A[i][j] == 0) {
			i++;
            if(i==n){return row;}
		}
		else {
            j++;
			row = i;
            if(j==n){return i;}
		}
	}
	return row;
}

int main(void) {
	int n = 0;
	scanf("%d", &n);
    int **A;
	A = (int**)malloc(sizeof(int*) * n);
	
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d", mostones(A, n));
	
	return 0;
}

/*
8 
1 1 1 1 0 0 0 0 
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/