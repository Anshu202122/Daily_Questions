class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> less, greater;
        int count = 0;
        for (int num : nums)
        {
            if (num < pivot)
            {
                less.push_back(num);
            }
            else if (num > pivot)
            {
                greater.push_back(num);
            }
            else
            {
                count++;
            }
        }
        while (count--)
        {
            less.push_back(pivot);
        }
        for (int ele : greater)
        {
            less.push_back(ele);
        }
        return less;
    }
};