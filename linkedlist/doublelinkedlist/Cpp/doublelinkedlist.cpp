#include <iostream>
#include "doublelinkedlist.h"

void DoubleLinkedList::append(int n)
{
    Node *new_node = new Node(n);
    if(length == -1)
    {
        head = new_node;
        tail = new_node;
    }
    else
        insert_tail(n);
    
    ++length;
}

void DoubleLinkedList::insert_head(int n)
{
    Node *new_node = new Node(n);
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void DoubleLinkedList::insert_tail(int n)
{
    Node *new_node = new Node(n);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}

void DoubleLinkedList::insert(int index, int n)
{
    if(index > length + 1 || index < 0)
    {
        std::cout << "Error" << std::endl;
        return;
    }

    if(length == -1)
    {
        Node *new_node = new Node(n);
        head = new_node;
        tail = new_node;
    }
    else if(index == 0)
        insert_head(n);
    else if(index == length + 1)
        insert_tail(n);
    else
    {
        Node *new_node = new Node(n);
        Node *before_node = get_node(index - 1);
        Node *after_node = before_node->next;

        before_node->next = new_node;
        new_node->prev = before_node;

        after_node->prev = new_node;
        new_node->next = after_node;
    }
    ++length;
}

void DoubleLinkedList::pop()
{
    if(length == -1)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    if(length == 0)
    {
        head = new Node(0);
        tail = new Node(0);
    }
    else
    {
        Node *pop_node = tail;
        tail = pop_node->prev;
        tail->next = nullptr;
        pop_node->prev = nullptr;
    }
    --length;
}

Node* DoubleLinkedList::get_node(int index)
{
    if(index > length + 1 || index < 0)
    {
        std::cout << "Error" << std::endl;
        return nullptr;
    }

    int count;
    Node *cur = new Node(0);
    if(index <= (length + 1) / 2)
    {
        count = 0;
        cur = head;
        while(count != index)
        {
            cur = cur->next;
            ++count;
        }
    }
    else
    {
        count = length;
        cur = tail;
        while(count != index)
        {
            cur = cur->prev;
            --count;
        }
    }

    return cur;
}

void DoubleLinkedList::display()
{
    Node *cur = (length == -1) ? head->next : head;
    while(cur)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void DoubleLinkedList::remove(int index)
{
    if(index >= length + 1 || index < 0 || length == -1)
    {
        std::cout << "Error" << std::endl;
        return;
    }

    if(length == 0 || index == length)
    {
        pop();
        return;
    }
    else if(index == 0)
    {
        Node *remove_node = head;
        head = remove_node->next;
        head->prev = nullptr;
        remove_node->next = nullptr;
    }
    else
    {
        Node *removed_node = get_node(index);
        removed_node->prev->next = removed_node->next;
        removed_node->next->prev = removed_node->prev;

        removed_node->next = nullptr;
        removed_node->prev = nullptr;
    }
    --length;
}

int DoubleLinkedList::check()
{
    return length + 1;
}

bool DoubleLinkedList::empty()
{
    return (length == -1) ? true : false;
}

int DoubleLinkedList::find_middle()
{
    if(length == -1)
        return -1;

    Node *slow = head;
    Node *fast = head;

    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}

void DoubleLinkedList::reverse()
{
    if(length == -1)
        return;

    Node *temp = nullptr;
    Node *cur = head;

    tail = head;
    while(cur)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if(temp)
        head = temp->prev;
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