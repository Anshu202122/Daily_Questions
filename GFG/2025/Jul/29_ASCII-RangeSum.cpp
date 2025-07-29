class Solution
{
public:
    vector<int> asciirange(string &s)
    {
        int n = s.length();
        vector<int> ans;
        vector<int> firstOccur(26, -1);
        vector<int> lastOccur(26, -1);
        for (int i = 0; i < n; i++)
        {
            if (firstOccur[s[i] - 'a'] == -1)
            {
                firstOccur[s[i] - 'a'] = i;
            }
            else
            {
                lastOccur[s[i] - 'a'] = i;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (firstOccur[i] != -1 && lastOccur[i] != -1)
            {
                int sum = 0;
                for (int j = firstOccur[i] + 1; j < lastOccur[i]; j++)
                {
                    sum += (int)s[j];
                }
                if (sum != 0)
                {
                    ans.push_back(sum);
                }
            }
        }
        return ans;
    }
};