class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans;
        if (n % 2 != 0)
        {
            ans.push_back(0);
            n--;
        }
        int i = 0, j = -1;
        while (i < n / 2)
        {
            ans.push_back(i + 1);
            i++;
        }
        while (i > 0)
        {
            ans.push_back(j);
            i--;
            j--;
        }
        return ans;
    }
};