class Solution
{
public:
    int maxRectSum(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = i; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    temp[k] += mat[k][j];
                }
                int sum = 0, maxSum = INT_MIN;
                for (int k = 0; k < n; k++)
                {
                    sum += temp[k];
                    maxSum = max(maxSum, sum);
                    if (sum < 0)
                    {
                        sum = 0;
                    }
                }
                ans = max(ans, maxSum);
            }
        }
        return ans;
    }
};