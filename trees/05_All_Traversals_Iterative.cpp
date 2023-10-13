<<<<<<< HEAD
#include <iostream>
#include <queue>
#include<stack>
#include<algorithm>
using namespace std;
 

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int val)
    {
        data = val; 
        left = right = NULL;
    }
};

// tc : O(n)
// sc :  o(n)  ~ O(height) for stack
void preorder(struct Node *node)
{
    if (node == NULL)
        return;
    
     stack<struct Node *> s;
     s.push(node);
     while(!s.empty())
     {
         struct Node * topEle = s.top();
         cout<<topEle->data<<" ";
         s.pop();
         if(topEle->right!=NULL)
         s.push(topEle->right);
         if(topEle->left!=NULL)
         s.push(topEle->left);
     }
}

// tc : O(n)
// sc : o(n)  ~ O(height) for stack
void inorder(struct Node *node)
{
    if (node == NULL)
        return;
    stack<struct Node *> s;
    struct Node *temp = node;
    while (true)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty())
                break;
            temp = s.top();
            s.pop();
            cout<<temp->data;
            temp = temp->right;
        }
    }
    
}

// vector<int> postorderUsingTwoStacks(struct Node *node)
// {
   
// }
//my way : = (best using 1 stack)
//TC : O(N)
//TC: O(N) ~O(height)
vector<int> postorderUsingOneStack(struct Node *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;

    stack<struct Node *> st1;

    struct Node *node = root;
    st1.push(node);
    while (!st1.empty())
    {
        struct Node *Top = st1.top();
        ans.push_back(Top->data);
        st1.pop();
        if (Top->left != NULL)
            st1.push(Top->left);
        if (Top->right != NULL)
            st1.push(Top->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void print(vector<int> ans)
{
    for(int e : ans)
    {
        cout<<e<<endl;
    }
}


int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    cout << "preorder traversal : ";
    preorder(root);
    cout << endl<< "inorder traversal : ";
    inorder(root);
    cout << endl<< "postorder traversal : ";
    // print(postorderUsingTwoStacks(root));
    print(postorderUsingOneStack(root));
    
=======
#include <iostream>
#include <queue>
#include<stack>
#include<algorithm>
using namespace std;
 

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int val)
    {
        data = val; 
        left = right = NULL;
    }
};

// tc : O(n)
// sc :  o(n)  ~ O(height) for stack
void preorder(struct Node *node)
{
    if (node == NULL)
        return;
    
     stack<struct Node *> s;
     s.push(node);
     while(!s.empty())
     {
         struct Node * topEle = s.top();
         cout<<topEle->data<<" ";
         s.pop();
         if(topEle->right!=NULL)
         s.push(topEle->right);
         if(topEle->left!=NULL)
         s.push(topEle->left);
     }
}

// tc : O(n)
// sc : o(n)  ~ O(height) for stack
void inorder(struct Node *node)
{
    if (node == NULL)
        return;
    stack<struct Node *> s;
    struct Node *temp = node;
    while (true)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty())
                break;
            temp = s.top();
            s.pop();
            cout<<temp->data;
            temp = temp->right;
        }
    }
    
}

// vector<int> postorderUsingTwoStacks(struct Node *node)
// {
   
// }
//my way : = (best using 1 stack)
//TC : O(N)
//TC: O(N) ~O(height)
vector<int> postorderUsingOneStack(struct Node *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;

    stack<struct Node *> st1;

    struct Node *node = root;
    st1.push(node);
    while (!st1.empty())
    {
        struct Node *Top = st1.top();
        ans.push_back(Top->data);
        st1.pop();
        if (Top->left != NULL)
            st1.push(Top->left);
        if (Top->right != NULL)
            st1.push(Top->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void print(vector<int> ans)
{
    for(int e : ans)
    {
        cout<<e<<endl;
    }
}


int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    cout << "preorder traversal : ";
    preorder(root);
    cout << endl<< "inorder traversal : ";
    inorder(root);
    cout << endl<< "postorder traversal : ";
    // print(postorderUsingTwoStacks(root));
    print(postorderUsingOneStack(root));
    
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
} 