<<<<<<< HEAD
#include<iostream>
#include<queue>
using namespace std;
// ALL TRAVERSALS : 
//TC : O(N) //n= no of nodes 
//SC: O(N) for skewed tree

struct Node{
    int data;
    struct Node*left,*right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void preorder(struct Node *node)
{
   if(node==NULL)
    return;
    cout<<node->data<<" ";
   preorder(node->left);
   preorder(node->right);
}
void inorder(struct Node *node)
{
   if(node==NULL)
    return;
   inorder(node->left);
   cout << node->data << " ";
   inorder(node->right);


}
void postorder(struct Node *node)
{
   if(node==NULL)
    return;
   postorder(node->left);
   postorder(node->right);
    cout<<node->data<<" ";
}

vector<vector<int>> levelorder(struct Node *node)
{
    if (node == NULL)
        return {};
        
    vector<vector<int>> ans;
    queue<struct Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        while (n--)
        {
            struct Node * frontNode = q.front();
            if (frontNode->left != NULL)
                q.push(frontNode -> left);
            if (frontNode->right != NULL)
                q.push(frontNode->right);
            temp.push_back(frontNode -> data);
            q.pop();
        }
        ans.push_back(temp);
    }
    return ans;
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
    root->right->right-> right = new Node(10);
    cout<<"preorder traversal : ";
    preorder(root);
    cout<<endl<<"inorder traversal : ";
    inorder(root);
    cout<<endl<<"postorder traversal : ";
    postorder(root);
    cout<<endl<<"levelorder traversal : ";
    for (auto v : levelorder(root))
    {
        for(int num : v)
        {
            cout<<num<<" ";
        }
    }

=======
#include<iostream>
#include<queue>
using namespace std;
// ALL TRAVERSALS : 
//TC : O(N) //n= no of nodes 
//SC: O(N) for skewed tree

struct Node{
    int data;
    struct Node*left,*right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void preorder(struct Node *node)
{
   if(node==NULL)
    return;
    cout<<node->data<<" ";
   preorder(node->left);
   preorder(node->right);
}
void inorder(struct Node *node)
{
   if(node==NULL)
    return;
   inorder(node->left);
   cout << node->data << " ";
   inorder(node->right);


}
void postorder(struct Node *node)
{
   if(node==NULL)
    return;
   postorder(node->left);
   postorder(node->right);
    cout<<node->data<<" ";
}

vector<vector<int>> levelorder(struct Node *node)
{
    if (node == NULL)
        return {};
        
    vector<vector<int>> ans;
    queue<struct Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        while (n > 0)
        {
            struct Node * frontNode = q.front();
            if (frontNode->left != NULL)
                q.push(frontNode -> left);
            if (frontNode->right != NULL)
                q.push(frontNode->right);
            temp.push_back(frontNode -> data);
            q.pop();
            n--;
        }
        ans.push_back(temp);
    }
    return ans;
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
    root->right->right-> right = new Node(10);
    cout<<"preorder traversal : ";
    preorder(root);
    cout<<endl<<"inorder traversal : ";
    inorder(root);
    cout<<endl<<"postorder traversal : ";
    postorder(root);
    cout<<endl<<"levelorder traversal : ";
    for (auto v : levelorder(root))
    {
        for(int num : v)
        {
            cout<<num<<" ";
        }
    }

>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}