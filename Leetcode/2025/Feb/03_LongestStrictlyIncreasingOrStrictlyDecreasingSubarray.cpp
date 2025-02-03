class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int inc = 1, j = i + 1;
            while (j < n && nums[j] > nums[j - 1])
            {
                inc++;
                j++;
            }
            int dec = 1;
            j = i + 1;
            while (j < n && nums[j] < nums[j - 1])
            {
                dec++;
                j++;
            }
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};