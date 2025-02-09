class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long count = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] - i;
        }
        for (int i = 0; i < n; i++)
        {
            count += i - mp[nums[i]];
            mp[nums[i]]++;
        }
        return count;
    }
};