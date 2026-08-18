class Solution {
public:
    vector<int>dp;

    int solve(vector<int>& nums,int i,int n){
        if(i>n) return 0;

        if(dp[i]!=-1) return dp[i];
        int steal = nums[i] + solve(nums,i+2,n);
        int skip = solve(nums,i+1,n);

        return dp[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(101,-1);
        
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        // case 1 : take house of 0th indexed house
        int Zero_idx_house = solve(nums,0,n-2);

        // case 2 : take house of 1th indexed house
        dp.clear();
        dp.resize(101,-1);
        int one_idx_house = solve(nums,1,n-1);
        return max(Zero_idx_house,one_idx_house);
    }
};