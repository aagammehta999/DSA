#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Stack
{
    Node *top;
    Stack()
    {
        this->top = top;
    }
    void push(int data)
    {
        Node *temp = new Node(data); // new temporary node create hua hai
        temp->next = top;            // temp ke address mai top ka address save hoga
        top = temp;                  // top mai temp ki value savw hogi
    }
    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            int data = top->data;
            Node *temp = top;
            delete temp;
            return data;
        }
    }
};
