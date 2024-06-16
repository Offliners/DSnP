class Node {
    friend class LinkedList;
    public:
        Node(): val(0), next(nullptr) {};
        Node(int n): val(n), next(nullptr) {};
        ~Node() {};
    
    private:
        int val = 0;
        Node *next = nullptr;
};

class LinkedList {
    public:
        LinkedList() {};
        LinkedList(int n);
        void append(int n);
        void insert(int index, int n);
        void display();
        void remove(int index);
        int check();
        bool empty();
        int find_middle();
        void reverse();
        void free_list();

    private:
        Node *head = new Node(0);
};