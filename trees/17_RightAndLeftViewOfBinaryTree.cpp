<<<<<<< HEAD
vector<int> rightSideView(TreeNode *root)
{

    if (root == NULL)
        return {};
    vector<int> ans;
    map<int, int> nodes;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            TreeNode *node = q.front().first;
            int levelno = q.front().second;

            nodes[levelno] = node->val;
            q.pop();
            if (node->left != NULL)
                q.push({node->left, levelno + 1});
            if (node->right != NULL)
                q.push({node->right, levelno + 1});
        }
    }
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}
vector<int> leftView(Node *root)
{

    if (root == NULL)
        return {};
    vector<int> ans;
    map<int, int> nodes;
    queue<pair<struct Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            struct Node *node = q.front().first;

            int levelno = q.front().second;
            if (nodes.find(levelno) == nodes.end())
                nodes[levelno] = node->data;
            q.pop();
            if (node->left != NULL)
                q.push({node->left, levelno + 1});
            if (node->right != NULL)
                q.push({node->right, levelno + 1});
        }
    }
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}
=======
vector<int> rightSideView(TreeNode *root)
{

    if (root == NULL)
        return {};
    vector<int> ans;
    map<int, int> nodes;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            TreeNode *node = q.front().first;
            int levelno = q.front().second;

            nodes[levelno] = node->val;
            q.pop();
            if (node->left != NULL)
                q.push({node->left, levelno + 1});
            if (node->right != NULL)
                q.push({node->right, levelno + 1});
        }
    }
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}
vector<int> leftView(Node *root)
{

    if (root == NULL)
        return {};
    vector<int> ans;
    map<int, int> nodes;
    queue<pair<struct Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            struct Node *node = q.front().first;

            int levelno = q.front().second;
            if (nodes.find(levelno) == nodes.end())
                nodes[levelno] = node->data;
            q.pop();
            if (node->left != NULL)
                q.push({node->left, levelno + 1});
            if (node->right != NULL)
                q.push({node->right, levelno + 1});
        }
    }
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
