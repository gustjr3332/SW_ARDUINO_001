#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct {
    int p,l,r;
} NodeInfo;

int n;
NodeInfo info[101];

int find_index(int key) {
    for (int i = 0; i < n; i++) {
        if (info[i].p == key) return i;
    }
    return -1;
}

TreeNode* makeNode(int key) {
    if (key == 0) return NULL;
    int idx = find_index(key);
    if (idx == -1) return NULL;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = makeNode(info[idx].l);
    node->right = makeNode(info[idx].r);
    return node;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        
        scanf("%d %d %d", &info[i].p, &info[i].l, &info[i].r);
        
    }
    TreeNode* root = makeNode(info[0].p);


    int s;
    scanf("%d", &s);
    char path[101];
    for (int i = 0; i < s; i++) {
        scanf("%s", path);
        TreeNode* curr = root;
        printf(" %d", curr->key);
        for (int j = 0; path[j]; j++) {
            if (path[j] == 'L') curr = curr->left;
            else if (path[j] == 'R') curr = curr->right;
            if (curr) printf(" %d", curr->key);
        }
        printf("\n");
    }
    return 0;
}

