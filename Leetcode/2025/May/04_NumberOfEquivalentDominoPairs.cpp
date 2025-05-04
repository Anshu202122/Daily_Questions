class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int n = dominoes.size(), ans = 0;
        vector<string> arr;
        unordered_map<string, int> mp;
        for (auto vec : dominoes)
        {
            if (vec[0] > vec[1])
            {
                swap(vec[0], vec[1]);
            }
            string str = to_string(vec[0]);
            str += to_string(vec[1]);
            arr.push_back(str);
        }
        for (string s : arr)
        {
            if (mp.find(s) != mp.end())
            {
                ans += mp[s];
            }
            mp[s]++;
        }
        return ans;
    }
};