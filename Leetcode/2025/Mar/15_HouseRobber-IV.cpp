class Solution
{
public:
    bool isPossible(vector<int> &nums, int mid, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                count++;
                i++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = INT_MAX, r = 0;
        for (int &num : nums)
        {
            l = min(l, num);
            r = max(r, num);
        }
        int ans = r;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, mid, k))
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