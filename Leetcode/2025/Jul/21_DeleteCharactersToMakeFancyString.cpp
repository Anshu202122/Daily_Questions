class Solution
{
public:
    string makeFancyString(string s)
    {
        int n = s.length(), i = 1;
        string ans = "";
        ans += s[0];
        while (i < n)
        {
            int cnt = 1;
            while (i < n && s[i] == s[i - 1])
            {
                cnt++;
                if (cnt <= 2)
                {
                    ans += s[i];
                }
                i++;
            }
            if (i == n)
            {
                break;
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};