class Solution
{
public:
    int getCountRecur(int i, int j, int n, vector<vector<vector<int>>> &memo)
    {
        if (i < 0 || i >= 4 || j < 0 || j >= 3 || (i == 3 && (j == 0 || j == 2)))
        {
            return 0;
        }
        if (n == 1)
            return 1;
        if (memo[n][i][j] != -1)
            return memo[n][i][j];
        vector<vector<int>> dir = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int ans = 0;
        for (auto d : dir)
        {
            int x = i + d[0], y = j + d[1];
            ans += getCountRecur(x, y, n - 1, memo);
        }
        return memo[n][i][j] = ans;
    }
    int getCount(int n)
    {
        int ans = 0;
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans += getCountRecur(i, j, n, memo);
            }
        }
        return ans;
    }
};