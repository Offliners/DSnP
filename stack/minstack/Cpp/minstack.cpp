#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "minstack.h"

std::list<int> toList(std::stack<int> stack_copy)
{
    std::list<int> return_list;
    while(!stack_copy.empty())
    {
        return_list.push_back(stack_copy.top());
        stack_copy.pop();
    }
    std::reverse(return_list.begin(), return_list.end());
    return return_list;
}

void MinStack::push(int n)
{
    if(data.size() < maxsize)
    {
        data.push(n);
        if(min.empty() || n < min.top())
            min.push(n);
        else
            min.push(min.top());
    }
    else
        std::cout << "Full" << std::endl;
}

void MinStack::pop()
{
    if(!data.empty())
    {
        data.pop();
        min.pop();
    }
    else
        std::cout << "Empty" << std::endl;
}

int MinStack::top()
{
    return data.top();
}

void MinStack::display()
{
    for(auto item : toList(data))
        std::cout << item << " ";
}

int MinStack::check()
{
    return data.size();
}

bool MinStack::empty()
{
    return data.empty();
}

bool MinStack::full()
{
    return data.size() >= maxsize;
}

int MinStack::get_min()
{
    return min.top();
}