class Solution
{
public:
    int countTriangles(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        if (n < 3)
        {
            return 0;
        }
        sort(arr.begin(), arr.end());
        for (int i = 2; i < n; i++)
        {
            int j = 0, k = i - 1;
            while (j < k)
            {
                if (arr[j] + arr[k] > arr[i])
                {
                    ans += k - j;
                    k--;
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