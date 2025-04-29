class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(), max_ele = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            max_ele = max(max_ele, nums[i]);
        }
        int i = 0, j = 0, count = 0;
        while (j < n)
        {
            if (nums[j] == max_ele)
            {
                count++;
            }
            while (i <= j && count >= k)
            {
                ans += (n - j);
                if (nums[i] == max_ele)
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};