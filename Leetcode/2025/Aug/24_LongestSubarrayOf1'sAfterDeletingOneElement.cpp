class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 0, ans = 0, zero = 0;
        while (j < n)
        {
            while (j < n)
            {
                if (nums[j] == 0)
                {
                    zero++;
                }
                if (zero > 1)
                {
                    j++;
                    break;
                }
                ans = max(ans, j - i);
                j++;
            }
            while (i < n && zero > 1)
            {
                if (nums[i] == 0)
                {
                    zero--;
                }
                i++;
            }
        }
        return ans;
    }
};