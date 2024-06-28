#ifndef _BINARYTREE_H
#define _BINARYTREE_H

typedef struct NODE {
    int val;
    struct NODE *parent;
    struct NODE *left;
    struct NODE *right;
} Node;

typedef struct BINARYTREE {
    Node *root;
} BinaryTree;

void initialize_binarytree(int*);
void preorder_traversal(BinaryTree*);
void inorder_traversal(BinaryTree*);
void postorder_traversal(BinaryTree*);
void levelorder_traversal(BinaryTree*);
void free_binarytree(BinaryTree*);

#endif