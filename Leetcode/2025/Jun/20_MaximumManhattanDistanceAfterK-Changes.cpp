class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int n = s.length(), east = 0, west = 0, north = 0, south = 0, ans = 0;
        int md = 0, steps = 0, wastedSteps = 0, extra = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'E')
            {
                east++;
            }
            else if (s[i] == 'W')
            {
                west++;
            }
            else if (s[i] == 'N')
            {
                north++;
            }
            else if (s[i] == 'S')
            {
                south++;
            }
            md = abs(east - west) + abs(north - south);
            steps = i + 1;
            wastedSteps = steps - md;
            if (steps != md)
            {
                extra = min(2 * k, wastedSteps);
            }
            ans = max(ans, md + extra);
        }
        return ans;
    }
};