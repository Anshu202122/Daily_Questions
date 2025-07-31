class Solution
{
public:
    int powerfulInteger(vector<vector<int>> &intervals, int k)
    {
        int count = 0, ans = -1;
        map<int, int> mp;
        for (auto &vec : intervals)
        {
            mp[vec[0]]++;
            mp[vec[1] + 1]--;
        }
        for (auto &it : mp)
        {
            if (count >= k && it.second < 0)
            {
                ans = it.first - 1;
            }
            count += it.second;
            if (count >= k)
            {
                ans = it.first;
            }
        }
        return ans;
    }
};