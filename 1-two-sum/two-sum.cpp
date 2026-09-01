class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int ele = target - num;
            if(mp.find(ele) != mp.end()){
                return {i,mp[target - num]};
            }
            mp[nums[i]] = i;
        }

        return {};
        
    }
};