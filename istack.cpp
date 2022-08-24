#include <iostream>
using namespace std;
// stack implementation using linkedlist
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class stack
{
private:
    /* data */
public:
    node *top;
    stack()
    {
        this->top = NULL;
    }
    void push(int data)
    {
        node *newnode = new node(data);
        newnode->next = top;
        top = newnode;
    }
    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        int data = top->data;
        node *temp = top;
        top = top->next;
        delete temp;
        return data;
    }
};

stack::stack(/* args */)
{
}

stack::~stack()
{
}
