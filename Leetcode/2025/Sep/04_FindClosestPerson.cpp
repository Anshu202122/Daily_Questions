class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int dist1 = abs(z - x), dist2 = abs(z - y);
        if (dist1 < dist2)
        {
            return 1;
        }
        else if (dist1 > dist2)
        {
            return 2;
        }
        return 0;
    }
};