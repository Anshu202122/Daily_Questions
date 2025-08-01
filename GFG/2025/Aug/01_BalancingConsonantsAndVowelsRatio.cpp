class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int countBalanced(vector<string> &arr)
    {
        int n = arr.size(), sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (string str : arr)
        {
            for (char ch : str)
            {
                if (isVowel(ch))
                {
                    sum++;
                }
                else
                {
                    sum--;
                }
            }
            if (mp.find(sum) != mp.end())
            {
                ans += mp[sum];
            }
            mp[sum] = mp[sum] + 1;
        }
        return ans;
    }
};