class Solution
{
public:
    bool isPossible(vector<int> &ranks, long long mid, int cars)
    {
        long long count = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            count += sqrt(mid / ranks[i]);
        }
        return count >= cars;
    }
    long long repairCars(vector<int> &ranks, int cars)
    {
        int n = ranks.size();
        int maxR = *max_element(begin(ranks), end(ranks));
        long long l = 1;
        long long r = 1LL * maxR * cars * cars;
        long long ans = -1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (isPossible(ranks, mid, cars))
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