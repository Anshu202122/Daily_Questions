class Solution
{
public:
    int vowelCount(string &s)
    {
        int ans = 1;
        unordered_map<char, int> mp;
        for (char ch : s)
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                mp[ch]++;
            }
        }
        int len = mp.size();
        for (int i = 1; i <= len; i++)
        {
            ans *= i;
        }
        for (auto &it : mp)
        {
            ans *= it.second;
        }
        if (ans == 1 && len != 1)
        {
            return 0;
        }
        return ans;
    }
};