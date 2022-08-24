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
public:
    node *top;

    stack()
    {
        this->top = NULL;
    }
    void push(int data)
    {
        node *newnode = new node(data);
        newnode->next =top;
        top = newnode;
    }
    int pop()
    {
        if (this->top == NULL)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        int data = top->data;
        node *temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        return top->data;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        node *temp = top;
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
    //menu for stack
    int choice;
    stack s;

    cout<<"1.push\n2.pop\n3.peek\n4.isEmpty\n5.print\n6.exit\n";
    while (1)
    {
        cout<<"enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int data;
            cout<<"enter the data:";
            cin>>data;
            s.push(data);
            break;
        case 2:
            cout<<"popped data is:"<<s.pop()<<endl;
            break;
        case 3:
            cout<<"peeked data is:"<<s.peek()<<endl;
            break;
        case 4:
            if (s.isEmpty())
            {
                cout<<"stack is empty"<<endl;
            }
            else
            {
                cout<<"stack is not empty"<<endl;
            }
            break;
        case 5:

            s.print();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;
        }
    }
    return 0;
   
}
