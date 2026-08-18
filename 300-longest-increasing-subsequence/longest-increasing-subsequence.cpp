class Solution {
public: 
    vector<vector<int>> dp;
    int solve(vector<int>& nums,int i, int p){ // i = index , p = curr element
        if(i>=nums.size()) return 0;
        
        if(dp[i][p+1]!=-1) return dp[i][p+1];

        int take = 0;

        if(p==-1 || nums[p]<nums[i]){
            take = 1 + solve(nums,i+1,i);
        }

        int skip = solve(nums,i+1,p);

        return dp[i][p+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        dp.resize(n,vector<int>(n+1,-1));
        
        return solve(nums,0,-1);
    }
};