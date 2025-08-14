class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int n = num.size(), i = 0, j = 1;
        string ans = "";
        while (i + 2 < n)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                if (!ans.empty())
                {
                    if (ans[0] - '0' < num[i] - '0')
                    {
                        ans = num.substr(i, 3);
                    }
                }
                else
                {
                    ans = num.substr(i, 3);
                }
            }
            i++;
        }
        return ans;
    }
};