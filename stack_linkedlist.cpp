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
public:
    Node *top;

    Stack() // stack class ka constructor
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
            cout << "Empty Stack" << endl;
        }
        else
        {
            int data = top->data;
            Node *temp = top;
            delete temp;
            return data;
        }
    }
    int peak()
    {
        return top->data;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    // Node *temp; // obbject creation
    int choice;
    cout << "1.push\n2.pop\n3.peek\n4.isEmpty\n5.print\n6.exit\n";
    while (1)
    {
        cout << "enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "enter the data:";
            cin >> data;
            s.push(data);
            break;
        case 2:
            cout << "popped data is:" << s.pop() << endl;
            break;
        case 3:
            cout << "peeked data is:" << s.peak() << endl;
            break;
        case 4:
            if (s.isEmpty())
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                cout << "stack is not empty" << endl;
            }
            break;
        case 5:

            s.print();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "invalid choice" << endl;
            break;
        }
    }
}