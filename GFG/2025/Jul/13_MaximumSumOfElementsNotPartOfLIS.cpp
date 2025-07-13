class Solution
{
public:
    int nonLisMaxSum(vector<int> &arr)
    {
        int n = arr.size(), totalSum = 0, maxLen = 1, lisSum = INT_MAX;
        vector<int> len(n, 1);
        vector<int> sum(n);
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum[i] = arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && len[j] + 1 >= len[i])
                {
                    len[i] = len[j] + 1;
                    sum[i] = sum[j] + arr[i];
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (len[i] == maxLen)
            {
                lisSum = min(lisSum, sum[i]);
            }
        }
        return totalSum - lisSum;
    }
};