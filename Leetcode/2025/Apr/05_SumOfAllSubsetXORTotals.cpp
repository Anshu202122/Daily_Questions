class Solution
{
public:
    int solve(vector<int> &nums, int i, int x)
    {
        if (i == nums.size())
        {
            return x;
        }
        int take = solve(nums, i + 1, nums[i] ^ x);
        int skip = solve(nums, i + 1, x);
        return take + skip;
    }
    int subsetXORSum(vector<int> &nums)
    {
        return solve(nums, 0, 0);
    }
};