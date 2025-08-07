class Solution
{
public:
    int n;
    vector<vector<int>> dp;
    int solve1(vector<vector<int>> &fruits, int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= n)
        {
            return 0;
        }
        if (i == n - 1 && j == n - 1)
        {
            return 0;
        }
        if (i == j || i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int d1 = fruits[i][j] + solve1(fruits, i + 1, j - 1);
        int d2 = fruits[i][j] + solve1(fruits, i + 1, j);
        int d3 = fruits[i][j] + solve1(fruits, i + 1, j + 1);
        return dp[i][j] = max({d1, d2, d3});
    }
    int solve2(vector<vector<int>> &fruits, int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= n)
        {
            return 0;
        }
        if (i == n - 1 && j == n - 1)
        {
            return 0;
        }
        if (i == j || i < j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int d1 = fruits[i][j] + solve2(fruits, i - 1, j + 1);
        int d2 = fruits[i][j] + solve2(fruits, i, j + 1);
        int d3 = fruits[i][j] + solve2(fruits, i + 1, j + 1);
        return dp[i][j] = max({d1, d2, d3});
    }
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        n = fruits.size();
        int child1 = 0, child2 = 0, child3 = 0, i = 0, j = 0;
        dp.resize(n, vector<int>(n, -1));
        while (i < n && j < n)
        {
            child1 += fruits[i][j];
            dp[i][j] = 0;
            i++;
            j++;
        }
        child2 = solve1(fruits, 0, n - 1);
        child3 = solve2(fruits, n - 1, 0);
        return child1 + child2 + child3;
    }
};