class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.length(), ans = 0, powVal = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                ans++;
            }
            else
            {
                if (powVal <= k)
                {
                    k -= powVal;
                    ans++;
                }
            }
            if (powVal <= k)
            {
                powVal *= 2;
            }
        }
        return ans;
    }
};