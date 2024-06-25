#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

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
        BinaryTree(int);

    private:
        Node *root = new Node(0);
};



#endif