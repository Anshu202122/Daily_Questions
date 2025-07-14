class Solution
{
public:
    int cuts(string s)
    {
        if (s[0] == '0')
            return -1;
        int n = s.size();
        const int maxi = n + 1;
        unordered_set<int> powersOf5;
        int val = 1;
        while (val <= 1e9)
        {
            powersOf5.insert(val);
            val *= 5;
        }
        vector<int> dp(n + 1, maxi);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == '0')
                continue;
            int num = 0;
            for (int j = i; j < n; ++j)
            {
                num = num * 2 + (s[j] == '1');
                if (powersOf5.count(num))
                {
                    if (dp[j + 1] != maxi)
                    {
                        dp[i] = min(dp[i], 1 + dp[j + 1]);
                    }
                }
            }
        }
        return dp[0] >= maxi ? -1 : dp[0];
    }
};