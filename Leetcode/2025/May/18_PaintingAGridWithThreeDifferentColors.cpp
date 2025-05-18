class Solution
{
public:
    vector<string> states;
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    void generateStates(string curr, char prev, int l, int m)
    {
        if (l == m)
        {
            states.push_back(curr);
            return;
        }
        for (char ch : {'R', 'G', 'B'})
        {
            if (ch == prev)
            {
                continue;
            }
            generateStates(curr + ch, ch, l + 1, m);
        }
    }
    int solve(int idx, int col, int row)
    {
        if (col == 0)
        {
            return 1;
        }
        if (dp[col][idx] != -1)
        {
            return dp[col][idx];
        }
        int ways = 0;
        string prev = states[idx];
        for (int i = 0; i < states.size(); i++)
        {
            if (i == idx)
            {
                continue;
            }
            string curr = states[i];
            bool valid = true;
            for (int j = 0; j < row; j++)
            {
                if (prev[j] == curr[j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                ways = (ways + solve(i, col - 1, row)) % mod;
            }
        }
        return dp[col][idx] = ways;
    }
    int colorTheGrid(int m, int n)
    {
        int ans = 0;
        generateStates("", '#', 0, m);
        int size = states.size();
        dp = vector<vector<int>>(n + 1, vector<int>(size + 1, -1));
        for (int i = 0; i < states.size(); i++)
        {
            ans = (ans + solve(i, n - 1, m)) % mod;
        }
        return ans;
    }
};