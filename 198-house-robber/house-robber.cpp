class Solution {
public:

    // int dp[101];
    vector<int>dp; 
    int solve(vector<int>& nums,int i){
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int steal = nums[i]+solve(nums,i+2);
        int skip = solve(nums,i+1);

        return dp[i] =  max(skip,steal);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // memset(dp,-1,sizeof(dp));
        dp.clear();
        dp.resize(101,-1);
        return solve(nums,0);
    }
}; 