class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        int n = nums.size(), sum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int digitSum = 0, num = nums[i];
            while (num != 0)
            {
                digitSum += num % 10;
                num /= 10;
            }
            mp[digitSum].push_back(nums[i]);
        }
        for (auto &it : mp)
        {
            vector<int> vec = it.second;
            sort(vec.begin(), vec.end());
            int currSum = 0;
            if (vec.size() >= 2)
            {
                currSum = vec[vec.size() - 1] + vec[vec.size() - 2];
                sum = max(sum, currSum);
            }
        }
        if (sum != INT_MIN)
        {
            return sum;
        }
        return -1;
    }
};