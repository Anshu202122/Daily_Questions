class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        if (arr.size() == 1)
        {
            return 0;
        }
        sort(arr.begin(), arr.end());

        int diff = arr[arr.size() - 1] - arr[0];
        int small = arr[0] + k;
        int large = arr[arr.size() - 1] - k;

        if (small > large)
        {
            swap(small, large);
        }

        for (int i = 0; i < arr.size() - 1; i++)
        {
            int sub = arr[i + 1] - k;
            int add = arr[i] + k;

            if (sub < 0)
            {
                continue;
            }

            int minSmall = min(small, sub);
            int maxLarge = max(large, add);
            diff = min(diff, maxLarge - minSmall);
        }
        return diff;
    }
};