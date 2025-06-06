#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#include <stdio.h>

#define N 10
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef int element;
typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *makeNode(element e,TreeNode *left, 
    TreeNode *right) {

    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->key = e;
    node->left = left;
    node->right = right;
    return node;
}
TreeNode *insertNode(TreeNode *root,element key ) {
    if (root == NULL) {
        return makeNode(key, NULL, NULL);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    return root;
}
TreeNode *minValueNode(TreeNode *node) {
    TreeNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
int height(TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + MAX(height(root->left), height(root->right));
}
TreeNode *deleteNode(TreeNode *root, element key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1
        if (root->left == NULL) {
            TreeNode *tmp = root->right;
            free(root);
            return tmp;
        }
        //case 2
        else if (root->right == NULL) {
            TreeNode *tmp = root->left;
            free(root);
            return tmp;
        }
        // Case 3
        else {
            TreeNode *tmp = minValueNode(root->right);
            root->key = tmp->key;
            root->right = deleteNode(root->right, tmp->key);
        }
    }
    return root;
}
void preOrder(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    TreeNode *root = NULL;
    element keys[10] = {35,18,7,26,12,3,68,2,30,99};
    for(int i = 0; i < 10; i++){
        root = insertNode(root, keys[i]);
        preOrder(root);
        printf("\n");
    }
    deleteNode(root, 18);
    preOrder(root);
    
}

