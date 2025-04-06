class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> ans;
        vector<int> prev(n, -1);
        int idx = 0;
        int maxL = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                    if (dp[i] > maxL)
                    {
                        maxL = dp[i];
                        idx = i;
                    }
                }
            }
        }
        while (idx >= 0)
        {
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }

        return ans;
    }
};