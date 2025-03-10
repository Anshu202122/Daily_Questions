class Solution
{
public:
    bool isVowel(char &ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    long long countOfSubstrings(string word, int k)
    {
        int n = word.size();
        unordered_map<char, int> mp;
        vector<int> idx(n);
        int consIdx = n, i = 0, j = 0, count = 0;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            idx[i] = consIdx;
            if (!isVowel(word[i]))
            {
                consIdx = i;
            }
        }
        while (j < n)
        {
            char ch = word[j];
            if (isVowel(ch))
            {
                mp[ch]++;
            }
            else
            {
                count++;
            }
            while (count > k)
            {
                char c = word[i];
                if (isVowel(c))
                {
                    mp[c]--;
                    if (mp[c] == 0)
                    {
                        mp.erase(c);
                    }
                }
                else
                {
                    count--;
                }
                i++;
            }
            while (i < n && mp.size() == 5 && count == k)
            {
                int index = idx[j];
                ans += index - j;
                char c = word[i];
                if (isVowel(c))
                {
                    mp[c]--;
                    if (mp[c] == 0)
                    {
                        mp.erase(c);
                    }
                }
                else
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};