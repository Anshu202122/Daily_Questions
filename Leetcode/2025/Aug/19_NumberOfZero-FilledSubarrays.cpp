class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size(), i = 0;
        long long ans = 0;
        while (i < n)
        {
            if (nums[i] == 0)
            {
                int j = i;
                while (j < n && nums[j] == 0)
                {
                    j++;
                }
                long long m = j - i;
                ans += m * (m + 1) / 2;
                i = j;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};