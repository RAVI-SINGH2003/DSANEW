<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    struct Node *left, *right;
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};
int helper(Node *root, int &maxi)
{
    if (root == 0)
        return 0;
    int left = helper(root->left, maxi), right = helper(root->right, maxi);

    if (left < 0)
        left = 0;
    if (right < 0)
        right = 0;
    maxi = max(maxi, left + right + root->val);
    return max(left, right) + root->val;
}
int maxPathSum(Node *root)
{
    if (root == NULL)
        return 0;
    int maxi = INT_MIN;
    helper(root, maxi);
    return maxi;
=======
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    struct Node *left, *right;
    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};
int helper(Node *root, int &maxi)
{
    if (root == 0)
        return 0;
    int left = helper(root->left, maxi), right = helper(root->right, maxi);

    if (left < 0)
        left = 0;
    if (right < 0)
        right = 0;
    maxi = max(maxi, left + right + root->val);
    return max(left, right) + root->val;
}
int maxPathSum(Node *root)
{
    if (root == NULL)
        return 0;
    int maxi = INT_MIN;
    helper(root, maxi);
    return maxi;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}