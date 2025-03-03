class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        int n = arr.size(), i = 0, j = 0;
        int start = 0, end = 0;
        deque<int> mindq, maxdq;
        vector<int> ans;

        while (j < n)
        {
            while (!mindq.empty() && arr[mindq.back()] > arr[j])
            {
                mindq.pop_back();
            }
            while (!maxdq.empty() && arr[maxdq.back()] < arr[j])
            {
                maxdq.pop_back();
            }
            mindq.push_back(j);
            maxdq.push_back(j);

            while (arr[maxdq.front()] - arr[mindq.front()] > x)
            {
                if (i == maxdq.front())
                    maxdq.pop_front();
                if (i == mindq.front())
                    mindq.pop_front();
                i++;
            }
            if (j - i > end - start)
            {
                end = j;
                start = i;
            }
            j++;
        }
        for (int a = start; a <= end; a++)
        {
            ans.push_back(arr[a]);
        }
        return ans;
    }
};