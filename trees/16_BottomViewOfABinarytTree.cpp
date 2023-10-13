<<<<<<< HEAD

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    map<int, int> nodes;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            BinaryTreeNode<int> *node = q.front().first;
            int verticalno = q.front().second;
            nodes[verticalno] = node->data;
            q.pop();
            if (node->left != NULL)
                q.push({node->left, verticalno - 1});
            if (node->right != NULL)
                q.push({node->right, verticalno + 1});
        }
    }
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}
//TC :O(N)
=======

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    map<int, int> nodes;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            BinaryTreeNode<int> *node = q.front().first;
            int verticalno = q.front().second;
            nodes[verticalno] = node->data;
            q.pop();
            if (node->left != NULL)
                q.push({node->left, verticalno - 1});
            if (node->right != NULL)
                q.push({node->right, verticalno + 1});
        }
    }
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}
//TC :O(N)
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
//SC :O(N) +O(N) queue+ map