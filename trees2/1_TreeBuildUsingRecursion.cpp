#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildUp(node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter the left of " << data << "\n";
    root->left = buildUp(root);
    cout << "Enter the right of " << data << "\n";
    root->right = buildUp(root);
    return root;
}

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
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
void reverseLevelOrder(node *root)
{

    queue<node *> q;
    vector<vector<int>> v;
    vector<int> ds;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        if (temp == NULL)
        {
            v.push_back(ds);
            ds.clear();
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            ds.push_back(temp->data);
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
    for (int i = v.size(); i >= 0; i--)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}
void iterativePreOrder(node *root)
{
    stack<node *> st;
    node *curr = root;
    while (st.size() > 0 || curr != NULL)
    {

        if (curr != NULL)
        {
            int val = curr->data;
            cout << val << " ";
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top()->right;
            st.pop();
        }
    }
}
void iterativeInOrder(node *root)
{
    stack<node *> st;
    node *curr = root;
    while (st.size() > 0 || curr != NULL)
    {

        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            int val = st.top()->data;
            cout << val << " ";
            curr = st.top()->right;
            st.pop();
        }
    }
}

// from striver tc : o(2n) for skewed tree sc: o(n)
void iterativePostOrder(node *root)
{
    vector<int> ans;
    stack<node *> st;
    node *curr = root;
    while (curr != NULL || st.size() > 0)
    {

        // go to left until null
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        // if null
        else
        {

            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                cout << temp->data << " ";
                st.pop();
                while (st.size() > 0 && st.top()->right == temp)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                // we have moved right
                curr = temp;
            }
        }
    }
}
int main()
{
    node *root = NULL;
    root = buildUp(root);
    levelOrder(root);
    cout << "\n";
    reverseLevelOrder(root);
}