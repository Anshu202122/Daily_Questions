class Solution
{
public:
    int maxFreqSum(string s)
    {
        int n = s.length(), maxV = 0, maxC = 0;
        map<char, int> vowels;
        map<char, int> consonants;
        for (char c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vowels[c]++;
            }
            else
            {
                consonants[c]++;
            }
        }
        for (auto &it : vowels)
        {
            maxV = max(maxV, it.second);
        }
        for (auto &it : consonants)
        {
            maxC = max(maxC, it.second);
        }
        return maxV + maxC;
    }
};