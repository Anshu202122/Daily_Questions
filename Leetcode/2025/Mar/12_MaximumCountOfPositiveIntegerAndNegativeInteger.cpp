class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n - 1, neg = 0, pos = n;
        if (nums[h] < 0 || nums[l] > 0)
        {
            return n;
        }
        if (nums[l] == 0 && nums[h] == 0)
        {
            return 0;
        }
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] < 0)
            {
                neg = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] > 0)
            {
                pos = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return max(neg + 1, n - pos);
    }
};