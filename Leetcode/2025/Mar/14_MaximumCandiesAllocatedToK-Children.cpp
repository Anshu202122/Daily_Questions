class Solution
{
public:
    bool isPossible(vector<int> &candies, int mid, long long k)
    {
        long long count = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            count += candies[i] / mid;
            if (count >= k)
            {
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int n = candies.size(), maxC = 0, ans = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            maxC = max(maxC, candies[i]);
            sum += candies[i];
        }
        if (sum < k)
        {
            return 0;
        }
        int l = 1, r = maxC;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(candies, mid, k))
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