#include <bits/stdc++.h>
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

void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
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