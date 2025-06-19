class Solution
{
public:
    string caseSort(string &s)
    {
        int n = s.length();
        string upper = "", lower = "", ans = "";
        for (int i = 0; i < n; i++)
        {
            if (isupper(s[i]))
            {
                upper += s[i];
            }
            else
            {
                lower += s[i];
            }
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        int j = 0, k = 0;
        for (int i = 0; i < n; i++)
        {
            if (isupper(s[i]))
            {
                ans += upper[j];
                j++;
            }
            else
            {
                ans += lower[k];
                k++;
            }
        }
        return ans;
    }
};