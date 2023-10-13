<<<<<<< HEAD
bool helper(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->val != root2->val)
        return false;

    return helper(root1->left, root2->right) && helper(root1->right, root2->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    return helper(root->left, root->right);
}
=======
bool helper(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->val != root2->val)
        return false;

    return helper(root1->left, root2->right) && helper(root1->right, root2->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    return helper(root->left, root->right);
}
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
