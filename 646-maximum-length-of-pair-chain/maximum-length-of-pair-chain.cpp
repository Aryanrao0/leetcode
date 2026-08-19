class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>>& nums,int i,int p){   // p = previous elemnt
        if(i>=n){
            return 0;
        }

        if(p!=-1 && dp[i][p]!=-1){
            return dp[i][p];
        }

        int take = 0;
        if(p==-1 || nums[i][0]>nums[p][1]){
            take = 1 + solve(nums,i+1,i);
        }
        int skip = solve(nums,i+1,p);

        if(p!=-1){
            dp[i][p] = max(take, skip);
        }

        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return solve(nums,0,-1);
    } 
};