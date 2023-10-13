<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct Node *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
=======
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct Node *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}