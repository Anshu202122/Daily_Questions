class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int mid)
    {
        int sum = 0, st = 1;
        for (int a : arr)
        {
            sum += a;
            if (sum > mid)
            {
                st++;
                sum = a;
            }
        }
        return st <= k;
    }
    int findPages(vector<int> &arr, int k)
    {
        if (k > arr.size())
        {
            return -1;
        }
        int sum = 0, maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        int low = maxi, high = sum, ans = INT_MAX, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (isPossible(arr, k, mid))
            {
                ans = min(ans, mid);
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