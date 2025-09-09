class Solution
{
public:
    int assignHole(vector<int> &mices, vector<int> &holes)
    {
        int n = mices.size(), ans = 0;
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, abs(mices[i] - holes[i]));
        }
        return ans;
    }
};