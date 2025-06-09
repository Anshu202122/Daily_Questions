class Solution
{
public:
    void solve(int num, int n, vector<int> &ans)
    {
        if (num > n)
        {
            return;
        }
        ans.push_back(num);
        for (int i = 0; i < 10; i++)
        {
            int newNum = (num * 10) + i;
            if (newNum > n)
            {
                return;
            }
            solve(newNum, n, ans);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for (int i = 1; i < 10; i++)
        {
            solve(i, n, ans);
        }
        return ans;
    }
};