class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            int sum1 = nums[i];
            int j = i + 1;
            while (j < n && nums[j] > nums[j - 1])
            {
                sum1 += nums[j];
                j++;
            }
            sum = max(sum, sum1);
        }
        return sum;
    }
};