class Solution
{
public:
    void rearrange(vector<int> &arr, int x)
    {
        stable_sort(arr.begin(), arr.end(), [x](int a, int b)
                    {
            if (abs(a - x) < abs(b - x))
                return true;
            else
                return false; });
    }
};