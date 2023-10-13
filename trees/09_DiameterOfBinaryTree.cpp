<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
//Naive Approach : 
//going to each node
//finding max length of left part and right part and 
// summmation of them = i am maximising
//tc : o(n)
//sc : o(n)
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
int depth(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int heightleft = depth(root->left, maxi);
    int heightright = depth(root->right, maxi);
    maxi = max(maxi, heightleft + heightright);
    return max(heightleft,  heightright) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int maxi = 0;
    int val = depth(root, maxi);
    return maxi;
=======
#include <bits/stdc++.h>
using namespace std;
//Naive Approach : 
//going to each node
//finding max length of left part and right part and 
// summmation of them = i am maximising
//tc : o(n)
//sc : o(n)
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
int depth(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int heightleft = depth(root->left, maxi);
    int heightright = depth(root->right, maxi);
    maxi = max(maxi, heightleft + heightright);
    return max(heightleft,  heightright) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int maxi = 0;
    int val = depth(root, maxi);
    return maxi;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}