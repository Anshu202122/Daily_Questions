class Solution
{
public:
    int n;
    int solve(vector<int> &arr, int mid, int k)
    {
        int count = 0, i = 0;
        while (i < n)
        {
            int j = i, cnt = 0;
            while (j < n && arr[j] <= mid && cnt < k)
            {
                cnt++;
                j++;
            }
            if (cnt == k)
            {
                count++;
                i = j;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
    int minDaysBloom(vector<int> &arr, int k, int m)
    {
        n = arr.size();
        int maxEle = arr[0], ans = -1;
        for (int a : arr)
        {
            maxEle = max(maxEle, a);
        }
        int low = 1, high = maxEle;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (solve(arr, mid, k) >= m)
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