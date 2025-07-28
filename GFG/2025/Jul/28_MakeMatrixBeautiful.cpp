class Solution
{
public:
    int balanceSums(vector<vector<int>> &mat)
    {
        int n = mat.size(), s1 = 0, s2 = 0;
        vector<long long> rowSum, colSum;
        for (int i = 0; i < n; i++)
        {
            long long sum1 = 0, sum2 = 0;
            for (int j = 0; j < n; j++)
            {
                sum1 += mat[i][j];
                sum2 += mat[j][i];
            }
            rowSum.push_back(sum1);
            colSum.push_back(sum2);
        }
        int m1 = *max_element(rowSum.begin(), rowSum.end());
        int m2 = *max_element(colSum.begin(), colSum.end());
        for (int num : rowSum)
        {
            s1 += (m1 - num);
        }
        for (int num : colSum)
        {
            s2 += (m2 - num);
        }
        return max(s1, s2);
    }
};