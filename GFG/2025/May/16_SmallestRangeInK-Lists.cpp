class Solution
{
public:
    vector<int> findSmallestRange(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> pointers(n, 0);
        vector<int> smallestRange = {0, INT_MAX};
        while (true)
        {
            int currentMin = INT_MAX, currentMax = INT_MIN;
            int minListIndex = -1;
            for (int i = 0; i < n; i++)
            {
                int value = arr[i][pointers[i]];
                if (value < currentMin)
                {
                    currentMin = value;
                    minListIndex = i;
                }
                if (value > currentMax)
                {
                    currentMax = value;
                }
            }
            if (currentMax - currentMin < smallestRange[1] - smallestRange[0])
            {
                smallestRange[0] = currentMin;
                smallestRange[1] = currentMax;
            }
            pointers[minListIndex]++;
            if (pointers[minListIndex] == arr[minListIndex].size())
                break;
        }
        return smallestRange;
    }
};