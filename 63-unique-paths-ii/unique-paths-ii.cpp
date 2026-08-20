class Solution {
public:
    int dp[101][101];
    int solve(int sr,int sc,vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(sr<0 || sr>=m || sc<0 || sc>=n || obstacleGrid[sr][sc]!=0) return 0;
        if(sr==m-1 && sc==n-1) return 1;

        if(dp[sr][sc]!=-1) return dp[sr][sc];
        int right = solve(sr,sc+1,obstacleGrid);
        int down = solve(sr+1,sc,obstacleGrid);

        return dp[sr][sc] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,obstacleGrid);
    }
};