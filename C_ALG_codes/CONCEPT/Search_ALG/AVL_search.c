#pragma warning(disable:4996)
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//AVL Tree Implementation in C
//O(log n) for insert, delete, search
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

int height(TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + MAX(height(root->left), height(root->right));
}
int balance(TreeNode *root) {
    if (root == NULL) return 0;
    return height(root->left) - height(root->right);
}

TreeNode *RotateLL(TreeNode *root) {
    TreeNode *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
TreeNode *RotateRR(TreeNode *root) {
    TreeNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
TreeNode *RotateLR(TreeNode *root) {
    root->left = RotateRR(root->left);
    return RotateLL(root);
}
TreeNode *RotateRL(TreeNode *root) {
    root->right = RotateLL(root->right);
    return RotateRR(root);
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
    int bal = balance(root);
    if(bal > 1 && key < root->left->key) {
        return RotateLL(root);
    }
    if(bal < -1 && key > root->right->key) {
        return RotateRR(root);
    }
    if(bal > 1 && key > root->left->key) {
        return RotateLR(root);
    }
    if(bal < -1 && key < root->right->key) {
        return RotateRL(root);
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
void display(TreeNode *root, element key) {
    printf("insert :%d\n", key);
    preOrder(root);
    printf("\n");
}
int main(){
    TreeNode *root = NULL;
    element keys[10] = {5,1,3,7,8,9,6,4,2};
    for(int i = 0; i < 9; i++){
        root = insertNode(root, keys[i]);
        display(root, keys[i]);
    }
    
}

