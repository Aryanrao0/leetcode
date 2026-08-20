class Solution {
public:
    int m,n;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i>=m || j>=n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1){
            return dp[i][j] = grid[i][j] + solve(i,j+1,grid);
        }
        else if(j==n-1){
            return dp[i][j] = grid[i][j] + solve(i+1,j,grid);
        }
        else return dp[i][j] = grid[i][j] + min(solve(i+1,j,grid) ,solve(i,j+1,grid));

    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(0,0,grid);
    }
};