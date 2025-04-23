class Solution
{
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> mp;
        int maxsize = 0, count = 0;
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            int num = i;
            while (num != 0)
            {
                int t = num % 10;
                sum += t;
                num /= 10;
            }
            mp[sum]++;
            maxsize = max(maxsize, mp[sum]);
        }
        for (auto &it : mp)
        {
            if (it.second == maxsize)
            {
                count++;
            }
        }
        return count;
    }
};