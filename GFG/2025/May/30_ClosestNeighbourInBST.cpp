class Solution
{
public:
    vector<int> ans;
    void solve(Node *root)
    {
        if (!root)
        {
            return;
        }
        solve(root->left);
        ans.push_back(root->data);
        solve(root->right);
    }
    int findMaxFork(Node *root, int k)
    {
        solve(root);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (ans[i] <= k)
            {
                return ans[i];
            }
        }
        return -1;
    }
};