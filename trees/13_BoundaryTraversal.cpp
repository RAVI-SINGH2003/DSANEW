<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
//push left nodes  excluding leaf
//take leaf nodes
//take right nodes only excluding leaf
void leftBoundary(TreeNode<int> *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
        return;

    ans.push_back(node->data);
    node = (node->left != NULL) ? node->left : node->right;
    leftBoundary(node, ans);
}
void rightBoundary(TreeNode<int> *node, vector<int> &temp)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
        return;

    temp.push_back(node->data);
    node = (node->right != NULL) ? node->right : node->left;
    rightBoundary(node, temp);
}
void rootNodes(TreeNode<int> *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        ans.push_back(node->data);
        return;
    }

    rootNodes(node->left, ans);
    rootNodes(node->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    if (root == NULL)
        return {};

    if (root->left == NULL && root->right == NULL)
        return {root->data};

    vector<int> ans;

    // pushing rootnode in advance
    ans.push_back(root->data);
    leftBoundary(root->left, ans);
    rootNodes(root, ans);
    vector<int> temp;
    rightBoundary(root->right, temp);
    for (int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
    return ans;
}
//TC : O(H) +O(H) +O(N)(for leave nodes we traverse all nodes) = O(N)
=======
#include<bits/stdc++.h>
using namespace std;
//push left nodes  excluding leaf
//take leaf nodes
//take right nodes only excluding leaf
void leftBoundary(TreeNode<int> *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
        return;

    ans.push_back(node->data);
    node = (node->left != NULL) ? node->left : node->right;
    leftBoundary(node, ans);
}
void rightBoundary(TreeNode<int> *node, vector<int> &temp)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
        return;

    temp.push_back(node->data);
    node = (node->right != NULL) ? node->right : node->left;
    rightBoundary(node, temp);
}
void rootNodes(TreeNode<int> *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        ans.push_back(node->data);
        return;
    }

    rootNodes(node->left, ans);
    rootNodes(node->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    if (root == NULL)
        return {};

    if (root->left == NULL && root->right == NULL)
        return {root->data};

    vector<int> ans;

    // pushing rootnode in advance
    ans.push_back(root->data);
    leftBoundary(root->left, ans);
    rootNodes(root, ans);
    vector<int> temp;
    rightBoundary(root->right, temp);
    for (int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
    return ans;
}
//TC : O(H) +O(H) +O(N)(for leave nodes we traverse all nodes) = O(N)
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
//Sc : O(N)