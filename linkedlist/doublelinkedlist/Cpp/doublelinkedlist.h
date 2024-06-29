#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

class Node {
    friend class LinkedList;
    public:
        Node(): val(0), next(nullptr), prev(nullptr) {};
        Node(int n): val(n), next(nullptr), prev(nullptr) {};
        ~Node() {};
    
    private:
        int val = 0;
        Node *next = nullptr;
        Node *prev = nullptr;
};

class DoubleLinkedList {
    public:
        DoubleLinkedList() {};
        void append(int);
        void insert(int, int);
        void display();
        void remove(int);
        int check();
        bool empty();
        int find_middle();
        void reverse();
        void free_list();

    private:
        Node *head = new Node(0);
        Node *tail = new Node(0);
        int length = 0;
};

#endif