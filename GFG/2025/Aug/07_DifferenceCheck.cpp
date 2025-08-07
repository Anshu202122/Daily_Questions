class Solution
{
public:
    int convert(string str)
    {
        string h = str.substr(0, 2);
        string m = str.substr(3, 2);
        string s = str.substr(6, 2);
        int res = (stoi(h) * 3600) + (stoi(m) * 60) + stoi(s);
        return res;
    }
    int minDifference(vector<string> &arr)
    {
        int n = arr.size(), ans = INT_MAX, first = -1, second = -1;
        vector<bool> vis(86400, false);
        for (string str : arr)
        {
            int sec = convert(str);
            if (vis[sec])
            {
                return 0;
            }
            vis[sec] = true;
        }
        for (int i = 0; i < 86400; i++)
        {
            if (!vis[i])
            {
                continue;
            }
            if (second != -1)
            {
                ans = min(ans, i - second);
            }
            else
            {
                first = i;
            }
            second = i;
        }
        ans = min(ans, first + 86400 - second);
        return ans;
    }
};
