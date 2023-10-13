<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
//Naive Approach 
//TC:O(N*N)
//SC :O(N*N);
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};
int depth(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return max(depth(node->left), depth(node->right)) + 1;
}

bool isBalanced(TreeNode *root)
{

    if (root == NULL)
    {
        return true;
    }
    int height1 = depth(root->left);
    int height2 = depth(root->right);
    if (abs(height2 - height1) > 1)
        return false;
    return isBalanced(root->right) && isBalanced(root->left);
}

//Approach -2 use dynamic programming=optimised version of above
//TC :O(N) + O(N*LOGN)
//SC : o(N) +o(N) +o(N)
int depth(TreeNode *node, map<TreeNode *, int> &dp)
{
    if (node == NULL)
        return 0;
    if (dp[node] != 0)
        return dp[node];
    return dp[node] = max(depth(node->left, dp), depth(node->right, dp)) + 1;
}

bool helper(TreeNode *root, map<TreeNode *, int> &dp)
{
    if (root == NULL)
    {
        return true;
    }
    int height1 = dp[root->left];
    int height2 = dp[root->right];
    if (abs(height2 - height1) > 1)
        return false;
    return isBalanced(root->right) && isBalanced(root->left);
}

bool isBalanced(TreeNode *root)
{

    map<TreeNode *, int> dp;
    int value = depth(root, dp);
    return helper(root, dp);
}

//easy solution :
//tc : O(N)
//sc: O(N)
int depth(TreeNode *node, bool &res)
{
    if (node == NULL)
        return 0;
    int height1 = depth(node->left, res);
    int height2 = depth(node->right, res);
    if (abs(height2 - height1) > 1)
        res = false;
    return max(height1, height2) + 1;
}
bool isBalanced(TreeNode *root)
{
    bool res = true;
    int val = depth(root, res);
    return res;
}
// modified version of above easy solution
// tc : O(N)
// sc: O(N)
int depth(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int height1 = depth(node->left);
    int height2 = depth(node->right);

    if (height1 == -1 || height2 == -1)
        return -1;
    if (abs(height2 - height1) > 1)
        return -1;
    return max(height1, height2) + 1;
}
bool isBalanced(TreeNode *root)
{
    int val = depth(root);
    return val == -1 ? false : true;
=======
#include<bits/stdc++.h>
using namespace std;
//Naive Approach 
//TC:O(N*N)
//SC :O(N*N);
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};
int depth(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return max(depth(node->left), depth(node->right)) + 1;
}

bool isBalanced(TreeNode *root)
{

    if (root == NULL)
    {
        return true;
    }
    int height1 = depth(root->left);
    int height2 = depth(root->right);
    if (abs(height2 - height1) > 1)
        return false;
    return isBalanced(root->right) && isBalanced(root->left);
}

//Approach -2 use dynamic programming=optimised version of above
//TC :O(N) + O(N*LOGN)
//SC : o(N) +o(N) +o(N)
int depth(TreeNode *node, map<TreeNode *, int> &dp)
{
    if (node == NULL)
        return 0;
    if (dp[node] != 0)
        return dp[node];
    return dp[node] = max(depth(node->left, dp), depth(node->right, dp)) + 1;
}

bool helper(TreeNode *root, map<TreeNode *, int> &dp)
{
    if (root == NULL)
    {
        return true;
    }
    int height1 = dp[root->left];
    int height2 = dp[root->right];
    if (abs(height2 - height1) > 1)
        return false;
    return isBalanced(root->right) && isBalanced(root->left);
}

bool isBalanced(TreeNode *root)
{

    map<TreeNode *, int> dp;
    int value = depth(root, dp);
    return helper(root, dp);
}

//easy solution :
//tc : O(N)
//sc: O(N)
int depth(TreeNode *node, bool &res)
{
    if (node == NULL)
        return 0;
    int height1 = depth(node->left, res);
    int height2 = depth(node->right, res);
    if (abs(height2 - height1) > 1)
        res = false;
    return max(height1, height2) + 1;
}
bool isBalanced(TreeNode *root)
{
    bool res = true;
    int val = depth(root, res);
    return res;
}
// modified version of above easy solution
// tc : O(N)
// sc: O(N)
int depth(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int height1 = depth(node->left);
    int height2 = depth(node->right);

    if (height1 == -1 || height2 == -1)
        return -1;
    if (abs(height2 - height1) > 1)
        return -1;
    return max(height1, height2) + 1;
}
bool isBalanced(TreeNode *root)
{
    int val = depth(root);
    return val == -1 ? false : true;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}