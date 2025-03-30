class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length(), i = 0;
        vector<int> ans;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]] = i;
        }
        while (i < n)
        {
            int end = mp[s[i]];
            int j = i;
            while (j < end)
            {
                end = max(end, mp[s[j]]);
                j++;
            }
            ans.push_back(j - i + 1);
            i = j + 1;
        }
        return ans;
    }
};