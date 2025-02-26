class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = nums[0], maxCurrSum = nums[0];
        int minSum = nums[0], minCurrSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            maxCurrSum = max(nums[i], maxCurrSum + nums[i]);
            maxSum = max(maxSum, maxCurrSum);
            minCurrSum = min(nums[i], minCurrSum + nums[i]);
            minSum = min(minSum, minCurrSum);
        }
        return max(maxSum, abs(minSum));
    }
};