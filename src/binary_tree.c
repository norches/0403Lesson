#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) { return a - b; }

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    return node;
}

void insert(Node** root, int val) {
    if (*root == NULL) {
        *root = create_node(val);
        return;
    }
    if (compare((*root)->val, val) >= 0) {
        insert(&((*root)->left), val);
    } else {
        insert(&((*root)->right), val);
    }
}

// preorder
// onorder
// postorder

void print_preorder(Node* root, int indent) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < indent; i++) {
        printf("   ");
    }
    printf("%d\n", root->val);
    print_preorder(root->left, indent + 1);
    print_preorder(root->right, indent + 1);
}

void print_inorder(Node* root, int indent) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left, indent + 1);
    for (int i = 0; i < indent; i++) {
        printf("   ");
    }
    printf("%d\n", root->val);
    print_inorder(root->right, indent + 1);
}

void print_postorder(Node* root, int indent) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left, indent + 1);
    print_postorder(root->right, indent + 1);
    for (int i = 0; i < indent; i++) {
        printf("   ");
    }
    printf("%d\n", root->val);
}

int main() {
    Node* root = NULL;
    insert(&root, 20);
    insert(&root, 24);
    insert(&root, 19);
    insert(&root, 15);
    insert(&root, 21);
    insert(&root, 26);
    insert(&root, 14);
    insert(&root, 17);

    print_preorder(root, 1);
    printf("\n");
    print_inorder(root, 1);
    printf("\n");
    print_postorder(root, 1);

    return 0;
}