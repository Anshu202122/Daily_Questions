class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> ans(n);
        unordered_map<int, int> arr;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            if (arr.find(x) != arr.end())
            {
                int z = arr[x];
                mp[z]--;
                if (mp[z] == 0)
                {
                    mp.erase(z);
                }
            }
            arr[x] = y;
            mp[y]++;
            ans[i] = mp.size();
        }
        return ans;
    }
};