class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums1[i][0]] = nums1[i][1];
        }
        for (int i = 0; i < m; i++)
        {
            if (mp.find(nums2[i][0]) != mp.end())
            {
                mp[nums2[i][0]] += nums2[i][1];
            }
            else
            {
                mp[nums2[i][0]] = nums2[i][1];
            }
        }
        for (auto &it : mp)
        {
            ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};