class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> arr = nums;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        for (int i = n - k; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                ans.push_back(nums[i]);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                if (ans.size() == k)
                {
                    break;
                }
            }
        }
        return ans;
    }
};