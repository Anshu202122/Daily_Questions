class Solution
{
public:
    int solve(Node *root, int &ans)
    {
        if (!root)
        {
            return 0;
        }
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
    int diameter(Node *root)
    {
        int ans = INT_MIN;
        if (!root)
        {
            return 0;
        }
        solve(root, ans);
        return ans;
    }
};