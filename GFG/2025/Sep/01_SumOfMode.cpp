class Solution
{
public:
    int sumOfModes(vector<int> &arr, int k)
    {
        int n = arr.size();
        int sum = 0;
        unordered_map<int, int> mp;
        set<pair<int, int>> st;
        for (int i = 0; i < k; i++)
        {
            mp[arr[i]]++;
        }
        for (auto x : mp)
        {
            st.insert({x.second, -x.first});
        }
        int mode = -st.rbegin()->second;
        sum += mode;
        for (int i = k; i < n; i++)
        {
            int out = arr[i - k];
            int in = arr[i];
            st.erase({mp[out], -out});
            mp[out]--;
            if (mp[out] > 0)
            {
                st.insert({mp[out], -out});
            }
            else
            {
                mp.erase(out);
            }
            mp[in]++;
            st.insert({mp[in], -in});
            mode = -st.rbegin()->second;
            sum += mode;
        }
        return sum;
    }
};