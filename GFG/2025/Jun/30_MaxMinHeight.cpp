class Solution
{
public:
    bool solve(vector<int> &arr, int k, int w, int mid)
    {
        int n = arr.size(), d = 0, curr = 0;
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            curr += diff[i];
            int h = arr[i] + curr;
            if (h < mid)
            {
                d += (mid - h);
                if (d > k)
                {
                    return false;
                }
                diff[i] += (mid - h);
                curr += (mid - h);
                if (i + w <= n)
                {
                    diff[i + w] -= (mid - h);
                }
            }
        }
        return true;
    }
    int maxMinHeight(vector<int> &arr, int k, int w)
    {
        int n = arr.size(), minEle = arr[0], ans = 0;
        for (int i = 0; i < n; i++)
        {
            minEle = min(minEle, arr[i]);
        }
        int l = minEle, r = minEle + k;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (solve(arr, k, w, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};