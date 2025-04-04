class Solution
{
public:
    int solve(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        return max(l, r) + 1;
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        int l = solve(root->left);
        int r = solve(root->right);
        if (r == l)
        {
            return root;
        }
        else if (r > l)
        {
            return lcaDeepestLeaves(root->right);
        }
        return lcaDeepestLeaves(root->left);
    }
};