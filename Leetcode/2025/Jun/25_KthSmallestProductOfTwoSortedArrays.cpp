class Solution
{
public:
    long long solve(vector<int> &nums1, vector<int> &nums2, long long midPdt)
    {
        long long count = 0;
        int n = nums2.size();
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] >= 0)
            {
                int l = 0, r = n - 1, m = -1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    long long pdt = 1LL * nums1[i] * nums2[mid];
                    if (pdt <= midPdt)
                    {
                        m = mid;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                count += (m + 1);
            }
            else
            {
                int l = 0, r = n - 1, m = n;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    long long pdt = 1LL * nums1[i] * nums2[mid];
                    if (pdt <= midPdt)
                    {
                        m = mid;
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                count += (n - m);
            }
        }
        return count;
    }
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long ans = 0, l = -1e10, r = 1e10;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long count = solve(nums1, nums2, mid);
            if (count >= k)
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