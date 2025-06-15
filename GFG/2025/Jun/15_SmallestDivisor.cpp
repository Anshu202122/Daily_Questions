class Solution
{
public:
    int solve(vector<int> &arr, int mid)
    {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans += ceil((double)arr[i] / (double)mid);
        }
        return ans;
    }
    int smallestDivisor(vector<int> &arr, int k)
    {
        int n = arr.size(), maxEle = arr[0], ans = 0;
        for (int i = 0; i < n; i++)
        {
            maxEle = max(maxEle, arr[i]);
        }
        int l = 1, r = maxEle;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (solve(arr, mid) <= k)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};