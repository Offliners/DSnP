#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <vector>

class Node {
    friend class BinaryTree;
    public:
        Node(): val(0), left(nullptr), right(nullptr) {};
        Node(int n): val(n), left(nullptr), right(nullptr) {};
        ~Node() {};
    
    private:
        int val = 0;
        Node *left = nullptr;
        Node *right = nullptr;
};

class BinaryTree {
    public:
        BinaryTree() {};
        BinaryTree(std::vector<int>);
        void preorder_traversal(Node*);
        void inorder_traversal(Node*);
        void postorder_traversal(Node*);
        void levelorder_traversal();
        void free_tree(Node*);
        Node *root = new Node(0);
};

#endif