class Solution
{
public:
    int find(vector<int> &tops, vector<int> &bottoms, int val)
    {
        int n = tops.size(), topSwap = 0, bottomSwap = 0;
        for (int i = 0; i < n; i++)
        {
            if (tops[i] != val && bottoms[i] != val)
            {
                return -1;
            }
            else if (tops[i] != val)
            {
                topSwap++;
            }
            else if (bottoms[i] != val)
            {
                bottomSwap++;
            }
        }
        return min(topSwap, bottomSwap);
    }
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 6; i++)
        {
            int steps = find(tops, bottoms, i);
            if (steps != -1)
            {
                ans = min(ans, steps);
            }
        }
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};