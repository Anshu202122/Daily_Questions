class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int sum = nums[i] + nums[i + 2];
            if (nums[i + 1] == sum * 2)
            {
                ans++;
            }
        }
        return ans;
    }
};