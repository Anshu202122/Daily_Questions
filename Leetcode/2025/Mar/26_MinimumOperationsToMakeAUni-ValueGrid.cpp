class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> nums;
        for (auto &vec : grid)
        {
            for (int &num : vec)
            {
                nums.push_back(num);
            }
        }
        sort(nums.begin(), nums.end());
        int target = nums[nums.size() / 2], ans = 0;
        for (int &num : nums)
        {
            if (num % x != target % x)
            {
                return -1;
            }
            ans += abs(target - num) / x;
        }
        return ans;
    }
};