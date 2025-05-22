class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), q = queries.size();
        priority_queue<int> maxEnd;
        priority_queue<int, vector<int>, greater<int>> past;
        sort(queries.begin(), queries.end());
        int j = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < q && queries[j][0] == i)
            {
                maxEnd.push(queries[j][1]);
                j++;
            }
            nums[i] -= past.size();
            while (nums[i] > 0 && !maxEnd.empty() && maxEnd.top() >= i)
            {
                int end = maxEnd.top();
                maxEnd.pop();
                past.push(end);
                count++;
                nums[i]--;
            }
            if (nums[i] > 0)
            {
                return -1;
            }
            while (!past.empty() && past.top() <= i)
            {
                past.pop();
            }
        }
        return q - count;
    }
};