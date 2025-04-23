class Solution
{
public:
    vector<int> singleNum(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i : arr)
        {
            mp[i]++;
        }
        for (auto &it : mp)
        {
            if (it.second == 1)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};