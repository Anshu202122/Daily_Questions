class Solution
{
public:
    int missingNum(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size(), num = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                num++;
            }
            else
            {
                return num;
            }
        }
        return num;
    }
};