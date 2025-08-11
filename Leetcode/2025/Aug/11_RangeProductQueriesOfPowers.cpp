class Solution
{
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        int mod = 1e9 + 7;
        vector<int> powers;
        vector<int> ans;
        for (int i = 0; i < 32; i++)
        {
            if ((n & (1 << i)) != 0)
            {
                powers.push_back(1 << i);
            }
        }
        for (auto &q : queries)
        {
            int s = q[0];
            int e = q[1];
            long res = 1;
            for (int i = s; i <= e; i++)
            {
                res = (res * powers[i]) % mod;
            }
            ans.push_back(res);
        }
        return ans;
    }
};