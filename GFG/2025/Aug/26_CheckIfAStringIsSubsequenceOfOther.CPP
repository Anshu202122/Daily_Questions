class Solution
{
public:
    bool isSubSeq(string &s1, string &s2)
    {
        int n = s1.length(), m = s2.length(), i = 0, j = 0;
        if (n > m)
        {
            return false;
        }
        while (i < n && j < m)
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if (i < n)
        {
            return false;
        }
        return true;
    }
};