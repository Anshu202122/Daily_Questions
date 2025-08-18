class Solution
{
public:
    double epsilon = 0.1;
    bool solve(vector<double> &arr)
    {
        if (arr.size() == 1)
        {
            return abs(arr[0] - 24) <= epsilon;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                vector<double> temp;
                for (int k = 0; k < arr.size(); k++)
                {
                    if (i != k && j != k)
                    {
                        temp.push_back(arr[k]);
                    }
                }
                double a = arr[i];
                double b = arr[j];
                vector<double> val = {a + b, a - b, b - a, a * b};
                if (abs(a) > 0.0)
                {
                    val.push_back(b / a);
                }
                if (abs(b) > 0.0)
                {
                    val.push_back(a / b);
                }
                for (double v : val)
                {
                    temp.push_back(v);
                    if (solve(temp) == true)
                    {
                        return true;
                    }
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int> &cards)
    {
        int n = cards.size();
        vector<double> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back(1.0 * cards[i]);
        }
        return solve(arr);
    }
};