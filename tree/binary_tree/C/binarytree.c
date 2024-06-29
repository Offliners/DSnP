#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "binarytree.h"

void initialize_binarytree(BinaryTree *bt, int *data, int data_size)
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    initialize_queue(q);

    bt->root = (TreeNode*)malloc(sizeof(TreeNode));
    bt->root->val = data[0];
    bt->root->left = NULL;
    bt->root->right = NULL;

    queue_push(q, bt->root);
    int turn_left = 1;
    TreeNode *cur = (TreeNode*)malloc(sizeof(TreeNode));
    for(int i = 1; i < data_size; ++i)
    {
        TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
        n->val = data[i];
        n->left = NULL;
        n->right = NULL;
        queue_push(q, n);
        
        if(turn_left)
        {
            cur = queue_get_front(q);
            queue_pop(q);
            cur->left = n;
            turn_left = 0;
        }
        else
        {
            cur->right = n;
            turn_left = 1;
        }
    }

    free_queue(q);
}

void preorder_traversal(TreeNode *node)
{
    if(node)
    {
        printf("%d ", node->val);
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

void inorder_traversal(TreeNode *node)
{
    if(node)
    {
        preorder_traversal(node->left);
        printf("%d ", node->val);
        preorder_traversal(node->right);
    }
}

void postorder_traversal(TreeNode *node)
{
    if(node)
    {
        preorder_traversal(node->left);
        preorder_traversal(node->right);
        printf("%d ", node->val);
    }
}

void levelorder_traversal(TreeNode *node)
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    initialize_queue(q);
    queue_push(q, node);

    while(!queue_empty(q))
    {
        TreeNode *cur = queue_get_front(q);
        queue_pop(q);
        printf("%d ", cur->val);

        if(cur->left)
            queue_push(q, cur->left);
        
        if(cur->right)
            queue_push(q, cur->right);
    }

    free_queue(q);
}

void free_tree(TreeNode *node)
{
    if(!node)
        return;
    
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}