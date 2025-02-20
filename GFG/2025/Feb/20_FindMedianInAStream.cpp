class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        vector<double> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            left.push(arr[i]);
            int num = left.top();
            double median;
            right.push(num);
            left.pop();
            if (left.size() < right.size())
            {
                int ele = right.top();
                left.push(ele);
                right.pop();
            }
            if (left.size() != right.size())
            {
                median = left.top();
            }
            else
            {
                median = (double)(left.top() + right.top()) / 2;
            }
            ans.push_back(median);
        }
        return ans;
    }
};