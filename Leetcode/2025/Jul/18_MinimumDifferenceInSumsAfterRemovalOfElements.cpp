class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int N = nums.size();
        int n = N / 3, cnt = 0;
        long long maxSum = 0, minSum = 0;
        vector<long long> leftMin(N), rightMax(N);
        long long ans = LLONG_MAX;
        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        for (int i = 0; i < N - n; i++)
        {
            maxpq.push(nums[i]);
            minSum += nums[i];
            cnt++;
            if (cnt > n)
            {
                minSum -= maxpq.top();
                maxpq.pop();
            }
            leftMin[i] = minSum;
        }
        cnt = 0;
        for (int i = N - 1; i >= n; i--)
        {
            minpq.push(nums[i]);
            maxSum += nums[i];
            cnt++;
            if (cnt > n)
            {
                maxSum -= minpq.top();
                minpq.pop();
            }
            rightMax[i] = maxSum;
        }
        for (int i = n - 1; i < N - n; i++)
        {
            ans = min(ans, (long long)leftMin[i] - rightMax[i + 1]);
        }
        return ans;
    }
};