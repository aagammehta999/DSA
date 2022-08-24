#include <iostream>
#include <queue>
using namespace std;
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
    // Node *insertintobst(Node *root, int d)
    // {
    //     if (root == NULL)
    //     {
    //         root = new Node(d);
    //         return 0;
    //     }
    //     if (d > root->data)
    //     {
    //         root->right = insertintobst(root->right, d);
    //     }
    //     else
    //     {
    //         root->left = insertintobst(root->left, d);
    //     }
    //     return root;
    // }
    Node *minVal(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *maxVal(Node *root)
    {
        Node *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }
    void levelordertraversal(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
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
        inorder(root->left);
        inorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        inorder(root->right);
        cout << root->data << " ";
    }
    void deletefrombst(Node *&root, int d)
    {
        if (root == NULL)
        {
            return;
        }
        if (d < root->data)
        {
            deletefrombst(root->left, d);
        }
        else if (d > root->data)
        {
            deletefrombst(root->right, d);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                Node *temp = minVal(root->right);
                root->data = temp->data;
                deletefrombst(root->right, temp->data);
            }
        }
    }
};

int main()
{
    bst bstobj;

    Node *root = NULL;
    // menu for bst
    int choice = 0;
    int data=0;
    while (choice != -1)
    {
        cout << "1.insert" << endl;
        cout << "2.inorder" << endl;
        cout << "3.preorder" << endl;
        cout << "4.postorder" << endl;
        cout << "5.levelorder" << endl;
        cout << "6.delete" << endl;
        cout << "7.exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            bstobj.insert(data);
            break;
        case 2:
            bstobj.inorder(root);
            break;
        case 3:
            bstobj.preorder(root);
            break;
        case 4:
            bstobj.postorder(root);
            break;
        case 5:
            bstobj.levelordertraversal(root);
            break;
        case 6:
            int d;
            cout << "enter the data to be deleted" << endl;
            cin >> d;
            bstobj.deletefrombst(root, d);
            break;
        case 7:
            return 0;
        default:
            cout << "invalid choice" << endl;
        }
    }

    return 0;
}