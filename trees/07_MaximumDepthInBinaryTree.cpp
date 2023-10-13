<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
// Approach - 1 using levelorder traversal;
// TC :O(N)
// SC :O(N)
struct TreeNode{
    int val ;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data)
    {
       val =data;
       left = right = NULL;
    }
};
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    queue<struct TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {
            n--;
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        count++;
    }

    return count;
}

//Approach -2 
//using recursion
//TC :O(N)
//SC :O(N)
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int depth1 = maxDepth(root->left);
    int depth2 = maxDepth(root->right);
    return max(depth1, depth2) + 1;
=======
#include<bits/stdc++.h>
using namespace std;
// Approach - 1 using levelorder traversal;
// TC :O(N)
// SC :O(N)
struct TreeNode{
    int val ;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data)
    {
       val =data;
       left = right = NULL;
    }
};
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    queue<struct TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {
            n--;
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        count++;
    }

    return count;
}

//Approach -2 
//using recursion
//TC :O(N)
//SC :O(N)
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int depth1 = maxDepth(root->left);
    int depth2 = maxDepth(root->right);
    return max(depth1, depth2) + 1;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}