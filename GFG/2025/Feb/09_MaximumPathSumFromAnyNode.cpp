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
        if (left > 0 && right > 0)
        {
            ans = max(ans, left + right + root->data);
        }
        else if (left < 0 && right < 0)
        {
            ans = max(ans, root->data);
        }
        else
        {
            ans = max(ans, root->data + max(left, right));
        }
        return max(0, root->data + max(left, right));
    }
    int findMaxSum(Node *root)
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};