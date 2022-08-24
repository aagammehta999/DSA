#include <iostream>
#include <queue>
using namespace std;

// binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
class bst
{
public:
    Node *root;
    bst()
    {
        this->root = NULL;
    }
    void insert(int data)
    {
        Node *newnode = new Node(data);
        if (this->root == NULL)
        {
            this->root = newnode;
        }
        else
        {
            Node *temp = this->root;
            while (temp != NULL)
            {
                if (data < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    void takeinput(Node *root, int data)
    {
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void levelorder(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    Node *minVal(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

    }
    Node *deleteFromBst(Node *root, int val)
    {
        if (root == NULL)
            return root;

        if (root->data == val)
        { // 0child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }   
            // 1 child wala case
            if (root->left != NULL && root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            if (root->right != NULL && root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            // 2 child
            if (root->left != NULL && root->right != NULL)
            {
                int min = minVal(root->right)->data;
                root->data = min;
                root->right = deleteFromBst(root->right, val);
                return root;
            }
        }
        else if (root->data > val)
        {
            root->left = deleteFromBst(root->left, val);
            return root;
        }
        else
        {
            root->right = deleteFromBst(root->right, val);
            return root;
        }
    }
};

int main()
{
    // menu driven
    int choice;
    bst b;
    while (1)
    {
        cout << "1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Levelorder\n6.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data"<<endl;
            cin >> data;
            b.insert(data);
            break;
        case 2:
            b.inorder(b.root);
            break;
        case 3:
            b.preorder(b.root);
            break;
        case 4:
            b.postorder(b.root);
            break;
        case 5:
            b.levelorder(b.root);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice";
        }
    }
}