class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long sum = 0;
        int count = 0;
        int minval = INT_MAX;
        for (long long num : nums)
        {
            if ((num ^ k) > num)
            {
                count++;
                sum += (num ^ k);
            }
            else
            {
                sum += num;
            }
            minval = min((long long)minval, abs(num - (num ^ k)));
        }
        if (count % 2 == 0)
            return sum;
        return sum - minval;
    }
};