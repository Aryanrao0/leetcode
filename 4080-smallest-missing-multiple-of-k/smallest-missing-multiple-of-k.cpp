class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
                unordered_map<int, int> mp;

        for (int x : nums) {

            mp[x]++;

        }

        int ans = k;

        while (mp.count(ans)) {

            ans += k;

        }

        return ans;
    }
};