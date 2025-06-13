class Solution
{
public:
    bool solve(vector<int> &nums, int num, int p)
    {
        int i = 0, count = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i + 1] - nums[i] <= num)
            {
                count++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        return count >= p;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        int n = nums.size(), ans = INT_MAX;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (solve(nums, mid, p))
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