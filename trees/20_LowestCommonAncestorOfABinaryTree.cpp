<<<<<<< HEAD
bool helper(TreeNode *root, TreeNode *target, vector<TreeNode *> &ans)
{

    if (root == target)
    {
        ans.push_back(root);
        return true;
    }
    if (root == NULL)
        return false;
    ans.push_back(root);
    
    if (helper(root->left, target, ans))
        return true; //if i found the target then no need to go for right call so return  true;
    
    if (helper(root->right, target, ans))
        return true;
    ans.pop_back();
    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;
    vector<TreeNode *> temp1, temp2;
    helper(root, p, temp1);
    helper(root, q, temp2);
    TreeNode *ans = NULL;
    for (int i = 0; i < min(temp1.size(), temp2.size()); i++)
    {
        if (temp1[i] == temp2[i])
            ans = temp1[i]; 
    }
    return ans;
}
//TC :O(N)+ O(N) +O(N)
//SC :O(N) + O(N) + O(N)
//in case of skew tree

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;
        //as soon as we find p or q we will start returning p or q so that it can be known that 
        //p or q has been found out
    if (root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)  //means p and q both have been found so the node we are standing at is the LCA  
        return root;
    if (left == NULL && right != NULL)  //if in left i donot find porq byt in right i found something then tell it by returning right
    {
        return right;
    }
    else if (left != NULL && right == NULL) // if in left i donot find porq byt in left i found something then tell it by returning left
    {
        return left;
    }
    return NULL;
}
//TC :O(N)
=======
bool helper(TreeNode *root, TreeNode *target, vector<TreeNode *> &ans)
{

    if (root == target)
    {
        ans.push_back(root);
        return true;
    }
    if (root == NULL)
        return false;
    ans.push_back(root);
    
    if (helper(root->left, target, ans))
        return true; //if i found the target then no need to go for right call so return  true;
    
    if (helper(root->right, target, ans))
        return true;
    ans.pop_back();
    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;
    vector<TreeNode *> temp1, temp2;
    helper(root, p, temp1);
    helper(root, q, temp2);
    TreeNode *ans = NULL;
    for (int i = 0; i < min(temp1.size(), temp2.size()); i++)
    {
        if (temp1[i] == temp2[i])
            ans = temp1[i]; 
    }
    return ans;
}
//TC :O(N)+ O(N) +O(N)
//SC :O(N) + O(N) + O(N)
//in case of skew tree

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;
        //as soon as we find p or q we will start returning p or q so that it can be known that 
        //p or q has been found out
    if (root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)  //means p and q both have been found so the node we are standing at is the LCA  
        return root;
    if (left == NULL && right != NULL)  //if in left i donot find porq byt in right i found something then tell it by returning right
    {
        return right;
    }
    else if (left != NULL && right == NULL) // if in left i donot find porq byt in left i found something then tell it by returning left
    {
        return left;
    }
    return NULL;
}
//TC :O(N)
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
//SC :O(N)