class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int n = nums.size(), odd = 0, even = 0, alt = 1;
        for (int num : nums)
        {
            if (num % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        bool isOdd = nums[0] % 2 == 1 ? true : false;
        for (int i = 1; i < n; i++)
        {
            bool curr = nums[i] % 2 == 1 ? true : false;
            if (isOdd != curr)
            {
                alt++;
                isOdd = curr;
            }
        }
        return max({even, odd, alt});
    }
};