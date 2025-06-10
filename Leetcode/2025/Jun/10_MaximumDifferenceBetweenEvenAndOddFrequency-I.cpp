class Solution
{
public:
    int maxDifference(string s)
    {
        int maxOdd = 0, minEven = INT_MAX;
        unordered_map<char, int> mp;
        for (char &ch : s)
        {
            mp[ch]++;
        }
        for (auto it : mp)
        {
            if (it.second % 2 != 0)
            {
                maxOdd = max(maxOdd, it.second);
            }
            else
            {
                minEven = min(minEven, it.second);
            }
        }
        return maxOdd - minEven;
    }
};