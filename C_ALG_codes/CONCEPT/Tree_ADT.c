#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

// #define N 10
// #define MAX(a,b) ((a)>(b)?(a):(b))

// typedef int element;
// typedef struct TreeNode{
//     element data;
//     struct TreeNode *left, *right;
// }TreeNode;

// typedef struct TreeType{
//     TreeNode *root;
// }TreeType;
// void Init(TreeType *T){
//     T->root = NULL;
// }
// TreeNode *makeNode(element e,TreeNode *left, 
//     TreeNode *right) {

//     TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
//     node->data = e;
//     node->left = left;
//     node->right = right;
//     return node;
// }
// int NodeCount(TreeNode *root) {
//     if (root == NULL) return 0;
//     return 1 + NodeCount(root->left) + NodeCount(root->right);
// }
// //재귀적 방법으로 트리 노드 개수 카운트
// int leafNodeCount(TreeNode *root) {
//     if (root == NULL) return 0;
//     if (root->left == NULL && root->right == NULL) return 1;
//     return leafNodeCount(root->left) + leafNodeCount(root->right);
// }
// int height(TreeNode *root) {
//     if (root == NULL) return 0;
//     return 1 + MAX(height(root->left), height(root->right));
// }
// void treeReverse(TreeNode *root) {
//     if (root == NULL) return;
//     TreeNode *temp = root->left;
//     root->left = root->right;
//     root->right = temp;
//     treeReverse(root->left);
//     treeReverse(root->right);
// }
// //자식노드들에 대해서도 다 반전시키니 유의

// void preOrder(TreeNode *root) {
//     if (root == NULL) return;
//     printf("%d ", root->data);
//     preOrder(root->left);
//     preOrder(root->right);
// }
// void inOrder(TreeNode *root) {
//     if (root == NULL) return;
//     inOrder(root->left);
//     printf("%d ", root->data);
//     inOrder(root->right);
// }
// void postOrder(TreeNode *root) {
//     if (root == NULL) return;
//     postOrder(root->left);
//     postOrder(root->right);
//     printf("%d ", root->data);
// }
// int main(){
//     TreeNode *F8 = makeNode(80, NULL, NULL);
//     TreeNode *F7 = makeNode(130, NULL, NULL);
//     TreeNode *F6 = makeNode(120, F7, F8);
//     TreeNode *F5 = makeNode(90, NULL, NULL);
//     TreeNode *F4 = makeNode(70, NULL, NULL);
//     TreeNode *F3 = makeNode(50, NULL,F6 );
//     TreeNode *F2 = makeNode(30, F4, F5);
//     TreeNode *F1 = makeNode(20, F2, F3);
//     int n;
//     scanf("%d", &n);
//     printf("노드 개수 : %d\n", NodeCount(F1));
//     free(F1); free(F2); free(F3); free(F4); free(F5); free(F6); free(F7); free(F8);
// }


#define N 10
typedef struct TreeNode{
    element data;
    struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode* element;
typedef struct QueueType{
    element data[N];
    int front, rear;
}QueueType;
void Init(QueueType *Q){
    Q->front = Q->rear = -1;
}
//
void Init(QueueType *Q){
    Q->front = Q->rear = 0;
}
int IsFull(QueueType *Q){
    return (Q->rear + 1) % N == 0;
}
//circular queue
int IsEmpty(QueueType *Q){
    return Q->front == Q->rear;
}
int IsFull(QueueType *Q){
    return Q->rear== N-1;
}

void Enqueue(QueueType *Q, element e){
    if(IsFull(Q)){
        printf("overflow\n");
    }
    else{
    Q->rear ++;
    Q->data[Q->rear] = e;
    }
}

element Dequeue(QueueType *Q){
    if(IsEmpty(Q)){
        printf("underflow\n");
        return -1;
    }
    Q->front ++;
    return Q->data[Q->front];
}
element Peek(QueueType *Q){
    if(IsEmpty(Q)){
        printf("underflow\n");
        return -1;
    }
    return Q->data[Q->front+1];
}
void Print(QueueType *Q){
    if(IsEmpty(Q)) printf("NAN\n");
    else printf("Queue: ");
    for(int i = Q->front+1; i <= Q->rear; i++){
        printf(" %d", Q->data[i]);
    }
    printf("\n");
}

int main(void){
    QueueType Q;
    Init(&Q);
    srand(time(NULL));
    for(int i = 0; i < 7; i++){
        Enqueue(&Q, rand()%10+1);
    }
    Print(&Q);
    for(int i = 0; i < 3; i++){
    printf("Dequeue: %d\n", Dequeue(&Q));
    }
    Print(&Q);
    printf("Peek: %d\n", Peek(&Q));
    return 0;
}