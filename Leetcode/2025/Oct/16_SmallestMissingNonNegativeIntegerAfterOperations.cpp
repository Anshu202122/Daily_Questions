class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int num;
            if (nums[i] < 0) {
                num = ((nums[i] % value) + value) % value;
            } else {
                num = nums[i] % value;
            }
            mp[num]++;
        }
        while (!mp.empty() && mp.find(ans % value) != mp.end()) {
            mp[ans % value]--;
            if (mp[ans % value] == 0) {
                mp.erase(ans % value);
            }
            ans++;
        }
        return ans;
    }
};
