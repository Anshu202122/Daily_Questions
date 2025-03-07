class Solution
{
public:
    vector<bool> solve(int idx)
    {
        vector<bool> arr(idx + 1, true);
        arr[0] = false;
        arr[1] = false;
        for (int i = 2; i * i <= idx; i++)
        {
            if (arr[i] == true)
            {
                for (int j = 2; i * j <= idx; j++)
                {
                    arr[i * j] = false;
                }
            }
        }
        return arr;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> isPrime = solve(right);
        vector<int> prime;
        vector<int> ans = {-1, -1};
        int minDiff = INT_MAX;
        for (int i = left; i <= right; i++)
        {
            if (isPrime[i])
            {
                prime.push_back(i);
            }
        }
        for (int i = 1; i < prime.size(); i++)
        {
            int diff = prime[i] - prime[i - 1];
            if (diff < minDiff)
            {
                minDiff = diff;
                ans = {prime[i - 1], prime[i]};
            }
        }
        return ans;
    }
};