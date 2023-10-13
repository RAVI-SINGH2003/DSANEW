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

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
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