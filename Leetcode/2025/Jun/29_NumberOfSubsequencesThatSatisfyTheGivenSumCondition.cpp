class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size(), ans = 0, mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++)
        {
            power[i] = (power[i - 1] * 2) % mod;
        }
        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
            {
                int num = power[r - l]; // number of all the possible subsequences
                ans = (ans % mod + num) % mod;
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};