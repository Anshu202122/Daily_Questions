class Solution
{
public:
    int countValid(int n, vector<int> &arr)
    {
        int m = arr.size(), totalCount = 9 * pow(10, n - 1), cnt = 1;
        bool isZero = false;
        for (int i = 0; i < m; i++)
        {
            if (arr[i] == 0)
            {
                isZero = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0 && !isZero)
            {
                cnt *= (9 - m);
            }
            else
            {
                cnt *= (10 - m);
            }
        }
        return totalCount - cnt;
    }
};