#include<iostream>
using namespace std;
//queue impelementation using linkedlist
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
class queue
{
public:
    node *front;
    node *rear;
    queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(int data)
    {
        node *newnode = new node(data);
        if (this->front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    int dequeue()
    {
        if (front == NULL)
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        int data = front->data;
        node *temp = front;
        front = front->next;
        delete temp;
        return data;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        return front->data;
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{   //menu driven program
    int choice;
    queue q;
    cout<<"1.enqueue"<<endl;
    cout<<"2.dequeue"<<endl;
    cout<<"3.peek"<<endl;
    cout<<"4.isEmpty"<<endl;
    cout<<"5.print"<<endl;

    while(1)
    {
        cout<<"enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            int data;
            cout<<"enter the data"<<endl;
            cin>>data;
            q.enqueue(data);
            break;
        case 2:
            int data1;
            data1=q.dequeue();  
            cout<<"dequeued data is"<<data1<<endl;
            break;
        case 3:
            int data2;
            data2=q.peek(); 
            cout<<"peeked data is"<<data2<<endl;    
            break;
        case 4:
            bool data3;
            data3=q.isEmpty();  
            if(data3==true)
            {
                cout<<"queue is empty"<<endl;
            }
            else
            {
                cout<<"queue is not empty"<<endl;
            }
            break;
        case 5:
            q.print();
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;
        }
    }
    return 0;
}
