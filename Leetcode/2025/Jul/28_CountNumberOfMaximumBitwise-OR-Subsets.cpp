class Solution
{
public:
    int solve(vector<int> &nums, int idx, int currOr, int &maxOr)
    {
        if (idx == nums.size())
        {
            if (currOr == maxOr)
            {
                return 1;
            }
            return 0;
        }
        int take = solve(nums, idx + 1, currOr | nums[idx], maxOr);
        int skip = solve(nums, idx + 1, currOr, maxOr);
        return (take + skip);
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size(), maxOr = 0;
        for (int num : nums)
        {
            maxOr = maxOr | num;
        }
        return solve(nums, 0, 0, maxOr);
    }
};