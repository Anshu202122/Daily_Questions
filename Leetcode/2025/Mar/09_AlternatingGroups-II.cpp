class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        for (int i = 0; i < k - 1; i++)
        {
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        int i = 0, j = 1, ans = 0;
        while (j < n)
        {
            if (colors[j] == colors[j - 1])
            {
                i = j;
                j++;
                continue;
            }
            if (j - i + 1 == k)
            {
                i++;
                ans++;
            }
            j++;
        }
        return ans;
    }
};