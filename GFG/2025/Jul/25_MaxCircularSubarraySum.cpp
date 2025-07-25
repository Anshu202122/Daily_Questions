class Solution
{
public:
    int maxCircularSum(vector<int> &arr)
    {
        int n = arr.size(), sum = 0, minSum = arr[0], s1 = 0, maxSum = arr[0], s2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            s1 = max(s1 + arr[i], arr[i]);
            maxSum = max(maxSum, s1);
            s2 = min(s2 + arr[i], arr[i]);
            minSum = min(minSum, s2);
        }
        if (minSum == sum)
        {
            return maxSum;
        }
        return max(maxSum, sum - minSum);
    }
};