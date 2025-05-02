class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.length();
        vector<int> right(n), left(n);
        string ans(n, ' ');
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'R')
            {
                left[i] = i;
            }
            else if (dominoes[i] == '.')
            {
                left[i] = i > 0 ? left[i - 1] : -1;
            }
            else
            {
                left[i] = -1;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L')
            {
                right[i] = i;
            }
            else if (dominoes[i] == '.')
            {
                right[i] = i < n - 1 ? right[i + 1] : -1;
            }
            else
            {
                right[i] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int distR = abs(i - right[i]);
            int distL = abs(i - left[i]);
            if (right[i] == left[i])
            {
                ans[i] = '.';
            }
            else if (right[i] == -1)
            {
                ans[i] = 'R';
            }
            else if (left[i] == -1)
            {
                ans[i] = 'L';
            }
            else if (distR == distL)
            {
                ans[i] = '.';
            }
            else
            {
                ans[i] = distR < distL ? 'L' : 'R';
            }
        }
        return ans;
    }
};