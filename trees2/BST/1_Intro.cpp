#include <iostream>
#include <queue>
using namespace std;

//insertion in bst logn 
//search = logn
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            cout << "\n";
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            q.pop();
        }
    }
}

Node *insertToBST(int data, Node *&root)
{
    if (root == NULL)
    {
        Node *newNode = new Node(data);
        return newNode;
    }
    if (data < root->data)
        root->left = insertToBST(data, root->left);
    else
        root->right = insertToBST(data, root->right);
    return root;
}
void takeInput(Node *&root)
{
    int data;
    do
    {
        cin >> data;
        if (data != -1)
            root = insertToBST(data, root);
        else
            break;
    } while (data != 1);
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data to create BST : ";
    takeInput(root);
    levelOrder(root);
    return 0;
}