class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n && nums[j] - nums[i] <= 1)
            {
                j++;
            }
            if (nums[j - 1] - nums[i] == 1)
            {
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};