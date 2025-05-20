class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), m = queries.size();
        vector<int> diff(n, 0);
        vector<int> ans(n);
        for (int i = 0; i < m; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            diff[start] += 1;
            if (end + 1 < n)
            {
                diff[end + 1] -= 1;
            }
        }
        ans[0] = diff[0];
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] + diff[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] < nums[i])
            {
                return false;
            }
        }
        return true;
    }
};