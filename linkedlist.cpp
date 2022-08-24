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
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = head;
    }
    void insertAtHead(Node *&head, int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void insertAtTail(Node *&tail, int data)
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
    void printll(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertAtPosition(Node *&head, int position, int d)
    {
        Node *temp = head;
        int count = 1;

        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *nodeToInsert = new Node(d);

        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
    void deletenode(int position, Node *&head)
    {
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
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

    LinkedList linkedl1;
    Node *node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);

    linkedl1.insertAtTail(tail, 12);
    linkedl1.printll(head);
    // print(head);

    linkedl1.insertAtTail(tail, 15);
    linkedl1.printll(tail);

    linkedl1.insertAtPosition(head, 1, 122);
    linkedl1.printll(head);
}