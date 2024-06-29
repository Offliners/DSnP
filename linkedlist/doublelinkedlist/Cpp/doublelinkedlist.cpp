#include <iostream>
#include "doublelinkedlist.h"

void DoubleLinkedList::append(int n)
{
    Node *next = new Node(n);
    
    if(!head->next)
        head->next = next;
    else
    {
        Node *cur = head->next;
        while(cur->next)
            cur = cur->next;
        cur->next = next;
    }
}

void DoubleLinkedList::insert(int index, int n)
{
    int len = check();
    if(index > len || index < 0)
    {
        std::cout << "Error" << std::endl;
        return;
    }

    if(index == 0)
    {
        Node *origin_next = head->next;
        head->next = new Node(n);
        head->next->next = origin_next;
        return;
    }

    int count = 0;
    Node *cur = head->next;
    while(cur)
    {
        if(count == index - 1)
        {
            Node *origin_next = cur->next;
            cur->next = new Node(n);
            cur->next->next = origin_next;
            break;
        }

        ++count;
        cur = cur->next;
    }
}

void DoubleLinkedList::display()
{
    Node *cur = head->next;
    while(cur)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void DoubleLinkedList::remove(int index)
{
    int len = check();
    if(index >= len || index < 0)
    {
        std::cout << "Error" << std::endl;
        return;
    }

    if(index == 0)
    {
        head->next = head->next->next;
        return;
    }

    int count = 0;
    Node *cur = head->next;
    while(cur)
    {
        if(count == index - 1)
        {
            cur->next = cur->next->next;
            break;
        }

        ++count;
        cur = cur->next;
    }
}

int DoubleLinkedList::check()
{
    if(!head->next)
        return 0;

    int len = 0;
    Node *cur = head->next;
    while(cur)
    {
        ++len;
        cur = cur->next;
    }
    
    return len;
}

bool DoubleLinkedList::empty()
{
    return (!head->next) ? true : false;
}

int DoubleLinkedList::find_middle()
{
    if(!head->next)
        return -1;

    Node *slow = head->next;
    Node *fast = head->next;

    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}

void DoubleLinkedList::reverse()
{
    if(!head->next || !head->next->next)
        return;

    Node *cur = head->next;
    Node *prev = nullptr;
    Node *next = nullptr;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = new Node(0);
    head->next = prev;
}

void DoubleLinkedList::free_list()
{
    Node *temp;
    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}