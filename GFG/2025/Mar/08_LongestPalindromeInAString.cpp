class Solution
{
public:
    int solve(int l, int r, string &s)
    {
        int len = 0;
        while (l >= 0 && r < s.length())
        {
            if (s[l] == s[r])
            {
                len += 2;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        return len;
    }
    string longestPalindrome(string &s)
    {
        int n = s.length();
        int ans = 1, start = 0;
        for (int i = 0; i < n; i++)
        {
            int len = 1 + solve(i - 1, i + 1, s);
            if (len > ans)
            {
                ans = len;
                start = i - len / 2;
            }
        }
        for (int i = 1; i < n; i++)
        {
            int len = solve(i - 1, i, s);
            if (len > ans)
            {
                ans = len;
                start = i - len / 2;
            }
        }
        return s.substr(start, ans);
    }
};