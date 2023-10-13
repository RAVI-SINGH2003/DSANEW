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

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

// Using one stack
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

// Using two stacks
// from striver tc : o(n) sc: o(2n)
void iterativePostOrder(node *root)
{
    vector<int> ans;
    stack<node *> st1;
    stack<int> st2;
    st1.push(root);
    while (st1.size() > 0)
    {

        node *temp = st1.top();
        st1.pop();
        if (temp->left != NULL)
            st1.push(temp->left);
        if (temp->right != NULL)
            st1.push(temp->right);
        if (temp != NULL)
            st2.push(temp->data);
    }

    while (st2.size() > 0)
    {
        ans.push_back(st2.top());
        st2.pop();
    }
}
