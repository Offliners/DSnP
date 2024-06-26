#include <iostream>
#include <vector>
#include <queue>
#include "binarytree.h"

BinaryTree::BinaryTree(std::vector<int> data)
{
    std::queue<Node*> q;
    root->val = data.front();
    q.push(root);

    bool turn_left = true;
    Node *cur = new Node();
    for(int i = 1; i < data.size(); ++i)
    {
        Node *node = new Node(data[i]);
        q.push(node);

        if(turn_left)
        {
            cur = q.front();
            q.pop();
            cur->left = node;
            turn_left = false;
        }
        else
        {
            cur->right = node;
            turn_left = true;
        }
    }
}

void BinaryTree::preorder_traversal(Node *node)
{
    if(node)
    {
        std::cout << node->val << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

void BinaryTree::inorder_traversal(Node *node)
{
    if(node)
    {
        preorder_traversal(node->left);
        std::cout << node->val << " ";
        preorder_traversal(node->right);
    }
}

void BinaryTree::postorder_traversal(Node *node)
{
    if(node)
    {
        preorder_traversal(node->left);
        preorder_traversal(node->right);
        std::cout << node->val << " ";
    }
}

void BinaryTree::levelorder_traversal()
{
    std::queue<Node*> q;
    q.push(this->root);
    while(!q.empty())
    {
        Node *cur = q.front();
        q.pop();                          
        std::cout << cur->val << " ";

        if(cur->left)
            q.push(cur->left);

        if(cur->right)
            q.push(cur->right);
    }
}

void BinaryTree::free_tree(Node *node)
{
    if(!node)
        return;
    
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}