#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

#define N 10
typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left, *right;
}TreeNode;

typedef struct TreeType{
    TreeNode *root;
}TreeType;
void Init(TreeType *T){
    T->root = NULL;
}
TreeNode *makeNode(element e,TreeNode *left, 
    TreeNode *right) {

    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = e;
    node->left = left;
    node->right = right;
    return node;
}
void preOrder(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    if(root->left != NULL) printf("%d ", root->left->data);
    if(root->right != NULL) printf("%d ", root->right->data);
}

int main(){
    TreeNode *F8 = makeNode(80, NULL, NULL);
    TreeNode *F7 = makeNode(130, NULL, NULL);
    TreeNode *F6 = makeNode(120, F7, F8);
    TreeNode *F5 = makeNode(90, NULL, NULL);
    TreeNode *F4 = makeNode(70, NULL, NULL);
    TreeNode *F3 = makeNode(50, NULL,F6 );
    TreeNode *F2 = makeNode(30, F4, F5);
    TreeNode *F1 = makeNode(20, F2, F3);
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1: preOrder(F1); break;
    case 2: preOrder(F2); break;
    case 3: preOrder(F3); break;
    case 4: preOrder(F4); break;
    case 5: preOrder(F5); break;
    case 6: preOrder(F6); break;
    case 7: preOrder(F7); break;
    case 8: preOrder(F8); break;
    default: printf("-1"); break;
    }
    
    free(F1); free(F2); free(F3); free(F4); free(F5); free(F6); free(F7); free(F8);
}
