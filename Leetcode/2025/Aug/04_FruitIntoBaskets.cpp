class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size(), ans = 0, curr = 0, i = 0, j = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[fruits[j]]++;
            curr++;
            while (mp.size() > 2)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
                curr--;
            }
            ans = max(ans, curr);
            j++;
        }
        return ans;
    }
};