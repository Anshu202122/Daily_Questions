class Solution
{
public:
    vector<char> nextSmaller(string s)
    {
        int n = s.length();
        vector<char> ans(n);
        ans[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = min(ans[i + 1], s[i]);
        }
        return ans;
    }
    string robotWithString(string s)
    {
        int n = s.length();
        string t = "", p = "";
        vector<char> ns = nextSmaller(s);
        int i = 0;
        while (i < n)
        {
            t.push_back(s[i]);
            char minChar;
            if (i + 1 < n)
            {
                minChar = ns[i + 1];
            }
            else
            {
                s[i];
            }
            while (!t.empty() && t.back() <= minChar)
            {
                p += t.back();
                t.pop_back();
            }
            i++;
        }
        while (!t.empty())
        {
            p += t.back();
            t.pop_back();
        }
        return p;
    }
};