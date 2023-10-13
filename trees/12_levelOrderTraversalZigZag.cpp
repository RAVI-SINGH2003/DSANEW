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
vector<vector<int>> zigzagLevelOrder(struct TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> ans;
    queue<struct TreeNode *> q1;
    q1.push(root);
    bool ltor = true;
    while (!q1.empty())
    {

        int n = q1.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {

            struct TreeNode *front = q1.front();
            if (front->left != NULL)
                q1.push(front->left);
            if (front->right != NULL)
                q1.push(front->right);

            int index = (ltor) ? i : n - i - 1;

            temp[index] = front->val;
            q1.pop();
        }

        ltor = !ltor;
        ans.push_back(temp);
    }
    return ans;
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
vector<vector<int>> zigzagLevelOrder(struct TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> ans;
    queue<struct TreeNode *> q1;
    q1.push(root);
    bool ltor = true;
    while (!q1.empty())
    {

        int n = q1.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {

            struct TreeNode *front = q1.front();
            if (front->left != NULL)
                q1.push(front->left);
            if (front->right != NULL)
                q1.push(front->right);

            int index = (ltor) ? i : n - i - 1;

            temp[index] = front->val;
            q1.pop();
        }

        ltor = !ltor;
        ans.push_back(temp);
    }
    return ans;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}