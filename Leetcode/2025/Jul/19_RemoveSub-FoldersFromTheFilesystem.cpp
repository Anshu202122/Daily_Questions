class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        set<string> st;
        vector<string> ans;
        ans.push_back(folder[0]);
        st.insert(folder[0]);
        for (int i = 1; i < n; i++)
        {
            string str = folder[i];
            string s = str.substr(0, 2);
            int j = 2;
            while (j < str.length())
            {
                if (str[j] == '/' && st.find(s) != st.end())
                {
                    break;
                }
                s += str[j];
                j++;
            }
            if (s == str)
            {
                ans.push_back(str);
                st.insert(str);
            }
        }
        return ans;
    }
};