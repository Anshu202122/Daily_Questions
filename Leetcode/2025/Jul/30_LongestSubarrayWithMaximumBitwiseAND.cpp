class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxEle = nums[0], count = 0, ans = 0;
        for (int num : nums)
        {
            maxEle = max(maxEle, num);
        }
        for (int num : nums)
        {
            if (num == maxEle)
            {
                count++;
                ans = max(ans, count);
            }
            else
            {
                count = 0;
            }
        }
        return ans;
    }
};