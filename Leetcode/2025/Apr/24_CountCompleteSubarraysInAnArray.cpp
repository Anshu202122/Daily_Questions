class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 0, ans = 0;
        set<int> s;
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            s.insert(i);
        }
        int size = s.size();
        while (j < n)
        {
            mp[nums[j]]++;
            while (mp.size() == size)
            {
                ans += (n - j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};