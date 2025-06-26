class Solution
{
public:
    int minValue(string &s, int k)
    {
        vector<int> freq(26, 0);
        map<int, int> mp;
        int ans = 0, maxFreq = INT_MIN;
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
            {
                mp[freq[i]]++;
            }
            maxFreq = max(maxFreq, freq[i]);
        }
        while (k > 0)
        {
            int r = min(k, mp[maxFreq]);
            mp[maxFreq] -= r;
            mp[maxFreq - 1] += r;
            if (mp[maxFreq] == 0)
            {
                mp.erase(maxFreq--);
            }
            k -= r;
        }
        for (auto it : mp)
        {
            ans += it.first * it.first * it.second;
        }
        return ans;
    }
};