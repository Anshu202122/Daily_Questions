class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages,
                         vector<vector<int>> &friendships)
    {
        int m = languages.size(), maxLang = 0;
        unordered_set<int> sad;
        unordered_map<int, int> mp;
        for (auto &vec : friendships)
        {
            int u = vec[0] - 1;
            int v = vec[1] - 1;
            unordered_set<int> lang(languages[u].begin(), languages[u].end());
            bool canTalk = false;
            for (int l : languages[v])
            {
                if (lang.find(l) != lang.end())
                {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk)
            {
                sad.insert(u);
                sad.insert(v);
            }
        }
        for (int i : sad)
        {
            for (int l : languages[i])
            {
                mp[l]++;
                maxLang = max(maxLang, mp[l]);
            }
        }
        return sad.size() - maxLang;
    }
};