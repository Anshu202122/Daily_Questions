class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int i = n;
        while (i--)
        {
            int num = nums[n - 1];
            nums.pop_back();
            nums.insert(nums.begin(), num);
            bool sorted = true;
            for (int i = 1; i < n; i++)
            {
                if (nums[i - 1] > nums[i])
                {
                    sorted = false;
                }
            }
            if (sorted)
            {
                return true;
            }
        }
        return false;
    }
};