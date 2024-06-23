#ifndef _MINSTACK_H_
#define _MINSTACK_H_

#include <stack>
#include <list>

class MinStack {
    friend std::list<int> toList(std::stack<int>);
    public:
        MinStack (int n) : maxsize(n) {};
        void push(int);
        void pop();
        int top();
        void display();
        int check();
        bool empty();
        bool full();
        int get_min();

    private:
        int maxsize = 0;
        std::stack<int> data = {};
        std::stack<int> min = {};
};

#endif