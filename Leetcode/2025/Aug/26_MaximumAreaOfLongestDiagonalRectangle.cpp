class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int n = dimensions.size(), area = 0, maxDiagonal = 0;
        for (auto &d : dimensions)
        {
            int length = d[0];
            int width = d[1];
            int currDiagonal = (length * length) + (width * width);
            if (maxDiagonal < currDiagonal)
            {
                maxDiagonal = currDiagonal;
                area = length * width;
            }
            else if (maxDiagonal == currDiagonal)
            {
                area = max(area, length * width);
            }
        }
        return area;
    }
};