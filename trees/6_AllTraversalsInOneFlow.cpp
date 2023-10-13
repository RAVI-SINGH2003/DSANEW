<<<<<<< HEAD
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
// ALL TRAVERSALS :
// TC : O(N)
// SC: O(N) for skewed tree

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
void MahaTraversal(struct Node *node, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair<Node *, int>> st;
    st.push({node, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else if (it.second == 3)
        {
            post.push_back(it.first->data);
        }
    }
}
void print(vector<int> v)
{
    for (int num : v)
        cout << num << " ";
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
    vector<int> pre, in, post;
    MahaTraversal(root, pre, in, post);
    cout << "preorder traversal : ";
    print(pre);
    cout << endl
         << "inorder traversal : ";
    print(in);
    cout << endl
         << "postorder traversal : ";
    print(post);
=======
#include <iostream>
#include <queue>
#include<stack>
#include<utility>
using namespace std;
// ALL TRAVERSALS :
// TC : O(N)
// SC: O(N) for skewed tree

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
void MahaTraversal(struct Node *node, vector<int>&pre, vector<int>&in,vector<int>&post)
{
   stack<pair<Node*,int>>st;
   st.push({node,1});
   while(!st.empty())
   {
      auto it = st.top();
      st.pop();
      if(it.second==1)
      {
        pre.push_back(it.first->data);
        it.second++;
        st.push(it);
        if(it.first->left!=NULL)
        {
            st.push({it.first->left,1});
        }
      }
      else if(it.second==2)
      {
          in.push_back(it.first->data);
          it.second++;
          st.push(it);
          if (it.first->right != NULL)
          {
              st.push({it.first->right, 1});
          }
      }
      else if(it.second==3)
      {
          post.push_back(it.first->data);

      }
   }
   
}
void print(vector<int> v)
{
   for(int num : v) cout<<num<<" ";

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
   vector<int> pre,in,post;
   MahaTraversal(root,pre,in,post);
   cout << "preorder traversal : ";
   print(pre);
   cout << endl<< "inorder traversal : ";
   print(in);
   cout << endl << "postorder traversal : ";
   print(post);
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}