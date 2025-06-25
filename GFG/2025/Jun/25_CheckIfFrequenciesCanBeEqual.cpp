class Solution
{
public:
    bool sameFreq(string &s)
    {
        unordered_map<int, int> mp;
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        for (char c : freq)
        {
            if (c)
            {
                mp[c]++;
            }
        }
        if (mp.size() == 1)
        {
            return true;
        }
        else if (mp.size() >= 3)
        {
            return false;
        }
        auto it = mp.begin();
        int num1 = it->first, c1 = it->second;
        it++;
        int num2 = it->first, c2 = it->second;
        if ((num1 == 1 && c1 == 1) || (num2 == 1 && c2 == 1))
        {
            return true;
        }
        if (abs(num1 - num2) == 1 && ((num1 > num2 && c1 == 1) || (num2 > num1 && c2 == 1)))
        {
            return true;
        }
        return false;
    }
};