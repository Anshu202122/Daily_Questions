class Solution
{
public:
    vector<int> solveLeft(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 1; i < n; i++)
        {
            ans[i] = max(ans[i - 1], nums[i - 1]);
        }
        return ans;
    }
    vector<int> solveRight(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i + 1], nums[i + 1]);
        }
        return ans;
    }
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left = solveLeft(nums);
        vector<int> right = solveRight(nums);
        long long ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, (long long)(left[i] - nums[i]) * right[i]);
        }
        return ans;
    }
};