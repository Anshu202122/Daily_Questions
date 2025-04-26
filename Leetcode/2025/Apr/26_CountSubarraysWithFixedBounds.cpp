class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size(), minpos = -1, maxpos = -1, idx = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                idx = i;
            }
            if (nums[i] == minK)
            {
                minpos = i;
            }
            if (nums[i] == maxK)
            {
                maxpos = i;
            }
            int small = min(minpos, maxpos);
            int temp = small - idx;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};