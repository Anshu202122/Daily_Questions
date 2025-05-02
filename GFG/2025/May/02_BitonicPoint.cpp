class Solution
{
public:
    int findMaximum(vector<int> &arr)
    {
        int n = arr.size(), ans = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                ans = arr[i];
            }
        }
        return ans;
    }
};