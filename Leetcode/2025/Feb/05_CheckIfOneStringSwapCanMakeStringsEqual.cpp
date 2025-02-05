class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
        {
            return true;
        }
        unordered_map<char, int> mp;
        vector<int> idx;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                mp[s2[i]] = i;
            }
        }
        if (mp.size() != 2)
        {
            return false;
        }
        for (auto &it : mp)
        {
            idx.push_back(it.second);
        }
        swap(s2[idx[0]], s2[idx[1]]);
        if (s1 == s2)
        {
            return true;
        }
        return false;
    }
};