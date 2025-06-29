class Solution
{
public:
    bool solve(vector<int> &arr, int val, int k)
    {
        int n = arr.size(), i = 0, ans = 0;
        while (i < n)
        {
            int sum = 0;
            while (i < n && sum + arr[i] <= val)
            {
                sum += arr[i];
                i++;
            }
            ans++;
        }
        if (ans <= k)
        {
            return true;
        }
        return false;
    }
    int splitArray(vector<int> &arr, int k)
    {
        int n = arr.size(), maxEle = arr[0], ans = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            maxEle = max(maxEle, arr[i]);
            sum += arr[i];
        }
        int l = maxEle, r = sum;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (solve(arr, mid, k))
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