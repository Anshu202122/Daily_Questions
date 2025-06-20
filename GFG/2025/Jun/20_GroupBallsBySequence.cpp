class Solution
{
public:
    bool validgroup(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == -1)
                continue;
            int count = 0;
            int curr = arr[i];
            for (int j = i; j < arr.size(); j++)
            {
                if (arr[j] == curr)
                {
                    count++;
                    curr++;
                    arr[j] = -1;
                }
                if (count == k)
                    break;
            }
            if (count != k)
                return false;
        }
        return true;
    }
};