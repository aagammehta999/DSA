#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Tree
{
public:
    Node *buildTree(Node *root)
    {
        cout << "Enter the data ";
        int data;
        cin >> data;
        root = new Node(data);

        if (data == -1)
        {
            return NULL;
        }

        cout << "Enter data for inserting in left of " << data << endl;
        root->left = buildTree(root->left);
        cout << "Enter data for inserting in right of " << data << endl;
        root->right = buildTree(root->right);
        return root;
    }

    void levelOrderTraversal(Node *root)
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
                // purana level complete traverse ho chuka hai
                cout << endl;
                if (!q.empty())
                {
                    // queue still has some child ndoes
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

    void buildFromLevelOrder(Node* &root)
    {
        queue<Node *> q;
        cout << "Enter Data for root" << endl;
        int data;
        cin >> data;
        root = new Node(data);
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            
            //left node ka input lena 

            cout << "Enter the left node for " << temp->data << endl;
            int leftData;
            cin >> leftData;

            if (leftData != -1)
            {
                temp->left = new Node(leftData);
                q.push(temp->left);
            }

            //right node ka input lena 

            cout << "Enter the right node for " << temp->data << endl;
            int rightData;
            cin >> rightData;

            if (rightData != -1)
            {
                temp->right = new Node(rightData);
                q.push(temp->right);
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
};

int main()
{
    Tree tobj;

    Node *root = NULL;
    tobj.buildFromLevelOrder(root);

    tobj.levelOrderTraversal(root);

    // root = tobj.buildTree(root);

    // cout << "Level order travesel" << endl;
    // tobj.levelOrderTraversal(root);

    // cout << "Inorder Traversel" << endl;
    // tobj.inorder(root);

    // cout << "preorder" << endl;
    // tobj.preorder(root);

    // cout << "POst Order Traversel" << endl;
    // tobj.postorder(root);

    return 0;
}