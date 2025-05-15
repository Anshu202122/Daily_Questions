class Solution
{
public:
    int countSubstring(string &s)
    {
        int n = s.length(), count = n;
        unordered_map<char, int> mp;
        for (char &ch : s)
        {
            if (mp.find(ch) != mp.end())
            {
                count += mp[ch];
            }
            mp[ch]++;
        }
        return count;
    }
};