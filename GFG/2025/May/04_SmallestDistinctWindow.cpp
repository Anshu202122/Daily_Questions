class Solution
{
public:
    int findSubString(string &str)
    {
        int n = str.length();
        int ans = n;
        set<char> st;
        for (char c : str)
        {
            st.insert(c);
        }
        if (st.size() == n)
        {
            return n;
        }
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        while (j < n)
        {
            mp[str[j]]++;
            while (i <= j && mp.size() == st.size())
            {
                ans = min(ans, j - i + 1);
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};