class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> ans, arr;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3)
        {
            vector<int> temp = {nums[i], nums[i + 1], nums[i + 2]};
            if (nums[i + 2] - nums[i] <= k)
            {
                ans.push_back(temp);
            }
        }
        if (ans.size() != n / 3)
        {
            return arr;
        }
        return ans;
    }
};