#pragma warning(disable:4996)
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define INF 1000

#define N 7
#define TRUE 1
#define FALSE 0

char vName[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int visited[N],dist[N];

int graph[N][N] = {
    {0,25,INF,12,INF,INF,INF},
    {25,0,10,INF,15,INF,INF},
    {INF,10,0,INF,INF,INF,16},
    {12,INF,INF,INF,0,17,37,INF},
    {INF,15,INF,17,0,19,14},
    {INF,INF,INF,INF,37,19,0,42},
    {INF,INF,INF,16,INF,14,42,0},

};
void init(){
    for(int i = 0; i < N; i++){
        visited[i] = FALSE;
        dist[i] = INF;
    }
}
void Prim(int vNum){
    dist[vNum] = 0; // Start from the first vertex
    for(int i=0;i<N;i++){
        dist[i]= INF;
        visited[i] = FALSE;
        for(int anum = 0;anum < N;anum++){
            if(graph[vNum][anum] != 0 && graph[vNum][anum] < dist[anum]){
                dist[anum] = graph[vNum][anum];
            }
        }
    }

}
int getMinVertex(){
    int min = INF, minIndex = -1;
    for(int i = 0; i < N; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}
int main(){
    init();
    return 0;
}