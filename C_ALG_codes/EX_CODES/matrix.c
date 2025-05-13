#include <stdio.h>
//p5
int main(void) {
    int n, m;
    int X[101][101];
    scanf("%d %d", &n, &m);
    
    int value = 1;
    int totalDiagonals = n + m - 1;
    
   
    for (int diag = 0; diag < totalDiagonals; diag++) {
        int row = (diag < m) ? 0 : diag - m + 1;
        int col = (diag < m) ? diag : m - 1;
        
        
        while (row < n && col >= 0) {
            X[row][col] = value++;
            row++;
            col--;
        }
    }
    
    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" %d", X[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//p4
// int main(void){
//     int n, m;
//     int X[101][101];
//     int i, j;
//     scanf("%d %d", &n, &m);
    
//     int value = 1;
//     int rowStart = 0, rowEnd = n - 1;
//     int colStart = 0, colEnd = m - 1;
    
//     while (rowStart <= rowEnd && colStart <= colEnd) {

//         for (i = colStart; i <= colEnd; i++) {
//             X[rowStart][i] = value++;
//         }// 첫행 채우기

//         rowStart++;

//         for (i = rowStart; i <= rowEnd; i++) {
//             X[i][colEnd] = value++;
//         }//끝열 채우기

//         colEnd--;
        
//         if (rowStart <= rowEnd) {
          
//             for (i = colEnd; i >= colStart; i--) {
//                 X[rowEnd][i] = value++;
//             }
//             rowEnd--;
//         }//끝행 채우기
        
//         if (colStart <= colEnd) {
            
//             for (i = rowEnd; i >= rowStart; i--) {
//                 X[i][colStart] = value++;
//             }
//             colStart++;
//         }//첫열 채우기
//         }
    
    
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             printf(" %d", X[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }


// int main(void){
//     int n, m;
//     int X[101][101];
//     int i=0, j=0;
//     scanf("%d %d", &n, &m);
    
//     int value = 0;
//     int rowStart = 0, rowEnd = n - 1;
//     int colStart = 0, colreset = 0;

//     while((rowStart<n)||(colStart<m)){
//     while(j>colStart){
//         X[i][j] = value++;
//         j--;
//         i++;
//     }
//     if(j==colStart){
//         X[i][j] = value++;
//         if(i==rowEnd)colStart++;
//         i=rowStart;
//         j=colreset<m ? colreset++ : m-1;
//     }
//     if(j==m-1)rowStart++;
// }
// for (i = 0; i < n; i++) {
//     for (j = 0; j < m; j++) {
//         printf(" %d", X[i][j]);
//     }
//     printf("\n");
// }

// return 0;
// }