class Solution
{
public:
    string findLargest(vector<int> &arr)
    {
        int n = arr.size();
        string ans = "";
        auto comp = [](int &a, int &b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);
            if (s1 + s2 > s2 + s1)
            {
                return true;
            }
            return false;
        };
        sort(arr.begin(), arr.end(), comp);
        if (arr[0] == 0)
        {
            return "0";
        }
        for (int &num : arr)
        {
            ans += to_string(num);
        }
        return ans;
    }
};