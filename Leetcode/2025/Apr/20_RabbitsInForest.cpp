class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i : answers)
        {
            mp[i]++;
        }
        for (auto &it : mp)
        {
            int groupSize = it.first + 1;
            int count = it.second;
            int group = ceil((double)count / groupSize);
            ans += group * groupSize;
        }
        return ans;
    }
};