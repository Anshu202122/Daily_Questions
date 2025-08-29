class Solution
{
public:
    string smallestWindow(string &s, string &p)
    {
        int n = s.length(), m = p.length();
        int start = 0, winSize = INT_MAX, reqCount = m, i = 0, j = 0;
        if (m > n)
        {
            return "";
        }
        unordered_map<char, int> mp;
        for (char &ch : p)
        {
            mp[ch]++;
        }
        while (j < n)
        {
            char ch = s[j];
            if (mp[ch] > 0)
            {
                reqCount--;
            }
            mp[ch]--;
            while (reqCount == 0)
            {
                int curr = j - i + 1;
                if (winSize > curr)
                {
                    winSize = curr;
                    start = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                {
                    reqCount++;
                }
                i++;
            }
            j++;
        }
        if (winSize == INT_MAX)
        {
            return "";
        }
        return s.substr(start, winSize);
    }
};