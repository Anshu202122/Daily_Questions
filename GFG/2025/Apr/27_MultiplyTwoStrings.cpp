class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string &s1, string &s2)
    {
        bool neg = false;
        if (s1[0] == '-')
        {
            neg = !neg;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-')
        {
            neg = !neg;
            s2 = s2.substr(1);
        }
        int l1 = s1.length(), l2 = s2.length();
        vector<int> vec(l1 + l2, 0);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string ans = "";
        bool z = true;
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                vec[i + j] += (s1[i] - '0') * (s2[j] - '0');
                vec[i + j + 1] += vec[i + j] / 10;
                vec[i + j] %= 10;
            }
        }
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            if (vec[i] != 0)
            {
                z = false;
            }
            if (!z)
            {
                ans += vec[i] + '0';
            }
        }
        if (ans.empty())
        {
            return "0";
        }
        if (neg)
        {
            ans = "-" + ans;
        }
        return ans;
    }
};