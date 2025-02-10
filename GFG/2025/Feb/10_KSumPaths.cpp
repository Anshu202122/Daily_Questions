class Solution
{
public:
    void solve(Node *root, int k, int &ans, int sum, unordered_map<int, int> &mp)
    {
        if (!root)
        {
            return;
        }
        sum += root->data;
        if (sum == k)
        {
            ans++;
        }
        if (mp.find(sum - k) != mp.end())
        {
            ans += mp[sum - k];
        }
        mp[sum]++;
        solve(root->left, k, ans, sum, mp);
        solve(root->right, k, ans, sum, mp);
        mp[sum]--;
    }
    int sumK(Node *root, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        solve(root, k, ans, 0, mp);
        return ans;
    }
};