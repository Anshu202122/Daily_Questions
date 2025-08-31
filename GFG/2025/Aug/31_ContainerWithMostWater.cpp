class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size(), area = 0;
        int i = 0, j = n - 1;
        while (i < j)
        {
            int l = j - i;
            int b = min(arr[i], arr[j]);
            area = max(area, l * b);
            if (arr[i] == b)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return area;
    }
};