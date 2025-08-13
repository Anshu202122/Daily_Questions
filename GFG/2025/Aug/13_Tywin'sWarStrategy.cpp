class Solution
{
public:
    int minSoldiers(vector<int> &arr, int k)
    {
        int n = arr.size(), ans = 0, cnt = 0;
        int size;
        if (n % 2 == 0)
        {
            size = n / 2;
        }
        else
        {
            size = (n / 2) + 1;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] % k) == 0)
            {
                cnt++;
            }
            else
            {
                int num = abs(k - (arr[i] % k));
                pq.push(num);
            }
        }
        if (cnt >= size)
        {
            return 0;
        }
        while (!pq.empty() && cnt < size)
        {
            ans += pq.top();
            pq.pop();
            cnt++;
        }
        return ans;
    }
};