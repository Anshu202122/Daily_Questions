class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        int n = word.size(), ans = INT_MAX;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[word[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 26; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (freq[j] < freq[i])
                {
                    cnt += freq[j];
                }
                else if (abs(freq[j] - freq[i]) > k)
                {
                    cnt += abs(freq[j] - freq[i] - k);
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};