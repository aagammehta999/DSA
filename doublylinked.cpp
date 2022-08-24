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
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void print(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
            cout << endl;
        }
    }
    void insertAtHead(Node *&head, Node *&tail, int data)
    {
        if (head == NULL)
        {
            Node *temp = new Node(data);
            head = temp;
            tail = temp;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head->prev = temp;
            temp = head;
        }
    }
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        if (tail == NULL)
        {
            Node *temp = new Node(data);
            head = temp;
            tail = temp;
        }
        else
        {
            Node *temp = new Node(data);
            tail->next = temp;
            temp->prev = tail;
            temp = tail;
        }
    }
    void insertAtPosition(Node *&head, Node *&tail, int position, int data)
    {
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }
        Node *temp = head;
        int count = 1;

        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(head, tail, data);
            return;
        }
        
        Node *nodetoinsert = new Node(data);
        nodetoinsert->next = temp->next;
        nodetoinsert->prev = temp;
        temp->next->prev = nodetoinsert;
        temp->prev = nodetoinsert;
    }
    void deleteNode(int position, Node *&head)
    {
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            int count = 1;
            while (count < position)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
};
int main()
{
    DoublyLinkedList Dll;
    Node *tail = NULL;
    Node *head = NULL;
    Dll.print(head);
    Dll.insertAtHead(head, tail, 50);
    Dll.print(head);
}