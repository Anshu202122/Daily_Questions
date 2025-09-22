class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size(), maxFreq = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
            maxFreq = max(maxFreq, mp[num]);
        }
        for (auto it : mp) {
            if (it.second == maxFreq) {
                ans += it.second;
            }
        }
        return ans;
    }
};
