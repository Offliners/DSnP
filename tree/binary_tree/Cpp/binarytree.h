#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <vector>

class Node {
    friend class BinaryTree;
    public:
        Node(): val(0), parent(nullptr), left(nullptr), right(nullptr) {};
        Node(int n): val(n), parent(nullptr), left(nullptr), right(nullptr) {};
        ~Node() {};
    
    private:
        int val = 0;
        Node *parent = nullptr;
        Node *left = nullptr;
        Node *right = nullptr;
};


class BinaryTree {
    public:
        BinaryTree() {};
        BinaryTree(std::vector<int>);
        void preorder_traversal();
        void inorder_traversal();
        void postorder_traversal();
        void levelorder_traversal();
        void free_tree();
    private:
        Node *root = new Node(0);
};



#endif