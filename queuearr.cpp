#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue()
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    int dequeue()
    {
        if (rear == front)
        {
            cout << "queue is empty";
            return -1;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }
    void print()
    {
    }
    bool isempty()
    {
        if (front == rear)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    
};
int main()
{
    Queue q1;

    q1.enqueue(100);
}