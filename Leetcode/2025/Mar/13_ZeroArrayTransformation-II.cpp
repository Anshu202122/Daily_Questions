class Solution
{
public:
    bool isZero(vector<int> &nums, vector<vector<int>> &queries, int k)
    {
        vector<int> diff(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i <= k; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] += val;
            if (r + 1 < nums.size())
            {
                diff[r + 1] -= val;
            }
        }
        for (int i = 0; i < diff.size(); i++)
        {
            sum += diff[i];
            diff[i] = sum;
            if ((nums[i] - diff[i]) > 0)
            {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), q = queries.size();
        bool isAllZero = true;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                isAllZero = false;
                break;
            }
        }
        if (isAllZero)
        {
            return 0;
        }
        int l = 0, r = q - 1, k = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isZero(nums, queries, mid))
            {
                k = mid + 1;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return k;
    }
};