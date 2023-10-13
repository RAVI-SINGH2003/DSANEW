<<<<<<< HEAD
bool helper(TreeNode<int> *A, int B, vector<int> &ans)
{
    if (A == NULL)
        return false;
    if (A->data == B)
    {
        ans.push_back(A->data);
        return true;
    }

    ans.push_back(A->data);
    if (helper(A->left, B, ans))
        return true;
    if (helper(A->right, B, ans))
        return true;
    ans.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *A, int B)
{
    if (A == NULL)
        return {};
    vector<int> ans;
    helper(A, B, ans);
    return ans;
}
// TC :O(N)
// SC :O(N)
=======
bool helper(TreeNode<int> *A, int B, vector<int> &ans)
{
    if (A == NULL)
        return false;
    if (A->data == B)
    {
        ans.push_back(A->data);
        return true;
    }

    ans.push_back(A->data);
    if (helper(A->left, B, ans))
        return true;
    if (helper(A->right, B, ans))
        return true;
    ans.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *A, int B)
{
    if (A == NULL)
        return {};
    vector<int> ans;
    helper(A, B, ans);
    return ans;
}
// TC :O(N)
// SC :O(N)
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
