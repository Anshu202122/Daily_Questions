class Solution
{
public:
    void solve(Node *root, int sum, int len, int &ans, int &maxlen)
    {
        if (!root)
        {
            if (len > maxlen)
            {
                maxlen = len;
                ans = sum;
            }
            else if (len == maxlen && sum > ans)
            {
                ans = sum;
            }
            return;
        }
        solve(root->left, sum + root->data, len + 1, ans, maxlen);
        solve(root->right, sum + root->data, len + 1, ans, maxlen);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int ans = INT_MIN, maxlen = 0;
        if (!root)
        {
            return 0;
        }
        solve(root, 0, 0, ans, maxlen);
        return ans;
    }
};