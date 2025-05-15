class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < n; i++)
        {
            if (groups[i - 1] != groups[i])
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};