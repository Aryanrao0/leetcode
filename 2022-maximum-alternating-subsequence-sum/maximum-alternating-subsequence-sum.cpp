class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    long long solve(int i,vector<int>&nums,bool flag){
        if(i>=n) return 0;

        if(dp[i][flag]!=-1) return dp[i][flag];
        long long skip = solve(i+1,nums,flag);  
        int val = nums[i];
        if(flag==false){    // make element negative to add into sum 
            val = -val;
        }
        long long take = solve(i+1,nums,!flag) + val;
        return dp[i][flag] = max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        dp.clear();
        dp.resize(100001,vector<long long>(2,-1));
        return solve(0,nums,true); // 0 = even index and true : +
    }
};