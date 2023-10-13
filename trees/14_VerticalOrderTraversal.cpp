<<<<<<< HEAD
// eg : Input[3, 1, 4, 0, 2, 2]
// Expected [[0], [1], [ 3, 2, 2 ], [4]]
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> ans; //multiset is same as set but duplicaes are allowes
    map<int, map<int, multiset<int>>> nodes; //here we have taken map<int,multiset<int>> because for a given verticalno we can have different levelno and 
    // we want to store elements level wise so map will arrange in ascending order of levelno and if at one level more than 1 node then according to the values we will sort (this sone by multiset) and store 
    queue<pair<TreeNode *, pair<int, int>>> q;  // node ,verticalno,levelno
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            TreeNode *node = q.front().first;
            int verticalno = q.front().second.first;
            int levelno = q.front().second.second;
            nodes[verticalno][levelno].insert(node->val);
            q.pop();
            if (node->left != NULL)
                q.push({node->left, {verticalno - 1, levelno + 1}});
            if (node->right != NULL)
                q.push({node->right, {verticalno + 1, levelno + 1}});
        }
    }
    for (auto node : nodes)
    {
        vector<int> temp;
        for (auto p : node.second)
        {
            temp.insert(temp.end(), p.second.begin(), p.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}
// TC :O(N*logN) logn for multiset
=======
// eg : Input[3, 1, 4, 0, 2, 2]
// Expected [[0], [1], [ 3, 2, 2 ], [4]]
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> ans; //multiset is same as set but duplicaes are allowes
    map<int, map<int, multiset<int>>> nodes; //here we have taken map<int,multiset<int>> because for a given verticalno we can have different levelno and 
    // we want to store elements level wise so map will arrange in ascending order of levelno and if at one level more than 1 node then according to the values we will sort (this sone by multiset) and store 
    queue<pair<TreeNode *, pair<int, int>>> q;  // node ,verticalno,levelno
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            TreeNode *node = q.front().first;
            int verticalno = q.front().second.first;
            int levelno = q.front().second.second;
            nodes[verticalno][levelno].insert(node->val);
            q.pop();
            if (node->left != NULL)
                q.push({node->left, {verticalno - 1, levelno + 1}});
            if (node->right != NULL)
                q.push({node->right, {verticalno + 1, levelno + 1}});
        }
    }
    for (auto node : nodes)
    {
        vector<int> temp;
        for (auto p : node.second)
        {
            temp.insert(temp.end(), p.second.begin(), p.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}
// TC :O(N*logN) logn for multiset
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
// SC : O(N) +O(N)