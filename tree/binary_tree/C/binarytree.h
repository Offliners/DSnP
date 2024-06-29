#ifndef _BINARYTREE_H
#define _BINARYTREE_H

typedef struct TREENODE {
    int val;
    struct TREENODE *left;
    struct TREENODE *right;
} TreeNode;

typedef struct BINARYTREE {
    TreeNode *root;
} BinaryTree;

void initialize_binarytree(BinaryTree*, int*, int);
void preorder_traversal(TreeNode*);
void inorder_traversal(TreeNode*);
void postorder_traversal(TreeNode*);
void levelorder_traversal(TreeNode*);
void free_tree(TreeNode*);

#endif