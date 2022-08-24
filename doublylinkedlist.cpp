#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedlist
{
public:
    Node *head;
    DoublyLinkedlist()
    {
        this->head = head;
    }
    int getlength(Node *head)
    {
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
    }
    void insertatHead(Node *&head, int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertatTail(Node *&tail, int data)
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        temp = tail;
    }
    void print(Node *head)
    {
        Node *temp = head;
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
    DoublyLinkedlist dllobj;
    Node *head = NULL;
    Node *tail = NULL;
}