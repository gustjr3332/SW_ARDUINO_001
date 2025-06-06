#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

#define N 10

typedef int element;
typedef struct TreeNode{
    element data;
    int id;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *makeNode(element e,TreeNode *left, 
    TreeNode *right, int id) {

    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = e;
    node->left = left;
    node->right = right;
    node->id = id;
    return node;
}

TreeNode* search(TreeNode *root, int ID) {
    if (root == NULL) return NULL;
    if(root->id == ID) return root;
    
    TreeNode* left = search(root->left, ID);
    if(left != NULL) return left;
    
    return search(root->right, ID);
}

int preOrderCal(TreeNode *root) {
    if (root == NULL) return 0;
    
    return root->data + 
           preOrderCal(root->left) + 
           preOrderCal(root->right);
}

int main(){
    TreeNode *F8 = makeNode(80, NULL, NULL,8);
    TreeNode *F7 = makeNode(130, NULL, NULL,7);
    TreeNode *F6 = makeNode(120, F7, F8,6);
    TreeNode *F5 = makeNode(90, NULL, NULL,5);
    TreeNode *F4 = makeNode(70, NULL, NULL,4);
    TreeNode *F3 = makeNode(50, NULL,F6,3);
    TreeNode *F2 = makeNode(30, F4, F5,2);
    TreeNode *F1 = makeNode(20, F2, F3,1);
    int n ,ID;
    scanf("%d", &ID);
    if(ID > 8 || ID < 1){
        printf("-1\n");
        return 0;
    }
    TreeNode *tmp = search(F1,ID);
    int sum=0;
    sum = preOrderCal(tmp);
    printf("%d\n", sum);
    // switch (n) {
    //     case 1:
    //         tmp = search(F1,ID);
    //         preOrderPrint(tmp);
    //         break;
    //     case 2:
    //         tmp = search(F1,ID);
    //         inOrderPrint(tmp);
    //         break;
    //     case 3:
    //         tmp = search(F1,ID);
    //         postOrderPrint(tmp);
    //         break;
    // }
    free(F1); free(F2); free(F3); free(F4); 
    free(F5); free(F6); free(F7); free(F8);
    
    return 0;
}