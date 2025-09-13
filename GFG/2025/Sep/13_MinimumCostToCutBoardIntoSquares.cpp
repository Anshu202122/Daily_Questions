class Solution
{
public:
    int minCost(int n, int m, vector<int> &x, vector<int> &y)
    {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int hCount = 1, vCount = 1;
        int i = x.size() - 1, j = y.size() - 1;
        int totalCost = 0;
        while (i >= 0 && j >= 0)
        {
            if (x[i] >= y[j])
            {
                totalCost += x[i] * hCount;
                vCount++;
                i--;
            }
            else
            {
                totalCost += y[j] * vCount;
                hCount++;
                j--;
            }
        }
        while (i >= 0)
        {
            totalCost += x[i] * hCount;
            vCount++;
            i--;
        }
        while (j >= 0)
        {
            totalCost += y[j] * vCount;
            hCount++;
            j--;
        }
        return totalCost;
    }
};