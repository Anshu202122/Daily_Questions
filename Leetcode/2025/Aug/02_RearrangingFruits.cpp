class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        int n = basket1.size(), minEle = INT_MAX;
        long long ans = 0;
        unordered_map<int, int> mp;
        vector<int> cost;
        for (int &x : basket1)
        {
            mp[x]++;
            minEle = min(minEle, x);
        }
        for (int &x : basket2)
        {
            mp[x]--;
            minEle = min(minEle, x);
        }
        for (auto &it : mp)
        {
            if (it.second == 0)
            {
                continue;
            }
            if (it.second % 2 != 0)
            {
                return -1;
            }
            for (int i = 1; i <= abs(it.second) / 2; i++)
            {
                cost.push_back(it.first);
            }
        }
        sort(cost.begin(), cost.end());
        for (int i = 0; i < cost.size() / 2; i++)
        {
            ans += min(cost[i], minEle * 2);
        }
        return ans;
    }
};