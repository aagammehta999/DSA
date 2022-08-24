#include <iostream>
using namespace std;

class Node
{
public:
    int data;   // data store hota hai
    Node *next; // next node ka address
                // parameterrised constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d); // create a temp node
    temp->next = head;        // temp node ke next pointer ke andar head ke andar wala address dena
    head = temp;              // head ko temp node ka address dena
}
void insertAtPosition(Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
    }

    int count = 1;
    Node *temp = new Node(d);
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
}
Node *reverselinkedlist(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }
    return prev;
}

// reverse using reucrsion

void reverse(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

void deleteNode(Node *&head, int position)
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
        Node *prev = curr;
        int count = 1;
        while (count < position)
        {
            prev = curr;       // iterating the prev forward
            curr = curr->next; // iterating the curr forward

            count++;
            /* code */
        }
        prev->next = curr->next; // linking the nodes
        // if (prev->next==NULL)
        // {

        // }
        curr->next = NULL;

        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;   // starting from the head
    while (temp != NULL) // until last node
    {
        cout << temp->data << " ";
        temp = temp->next; // next node pe jane ke liye
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
}