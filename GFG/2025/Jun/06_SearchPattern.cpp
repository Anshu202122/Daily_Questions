class Solution
{
public:
    vector<int> search(string &pat, string &txt)
    {
        int n = txt.size(), m = pat.size();
        vector<int> ans;
        vector<int> lps(m);
        int len = 0, i = 1;
        lps[0] = 0;
        while (i < m)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                    i++;
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int j = 0, k = 0;
        while (j < n)
        {
            if (txt[j] == pat[k])
            {
                j++;
                k++;
            }
            if (k == m)
            {
                ans.push_back(j - k + 1);
                k = lps[k - 1];
            }
            else if (txt[j] != pat[k])
            {
                if (k != 0)
                {
                    k = lps[k - 1];
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};