class Solution
{
public:
    int solve(vector<int> &arr, int s)
    {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans += ceil((double)arr[i] / (double)s);
        }
        return ans;
    }
    int kokoEat(vector<int> &arr, int k)
    {
        int n = arr.size(), ans = 0, maxEle = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxEle = max(maxEle, arr[i]);
        }
        int low = 1, high = maxEle;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int hrs = solve(arr, mid);
            if (hrs <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};