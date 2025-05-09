class Solution
{
public:
    string findMaximumNum(string &s, int k)
    {
        if (k == 0)
        {
            return s;
        }
        int n = s.length();
        string ans = s;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] < s[j])
                {
                    swap(s[i], s[j]);
                    ans = max(ans, findMaximumNum(s, k - 1));
                    swap(s[i], s[j]);
                }
            }
        }
        return ans;
    }
};