class Solution {
public:
    int solve(int sr,int sc,int er,int ec,vector<vector<int> > &dp  ){
        if(sr==er-1 && sc==ec-1) return 1;
        if(sr>er || sr<0 || sc<0 ||sc>ec) return 0;

        if(dp[sr][sc]!=-1) return dp[sr][sc];
        return dp[sr][sc] = solve(sr+1,sc,er,ec,dp) + solve(sr,sc+1,er,ec,dp);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m+1,vector<int> (n+1,-1));
        return solve(0,0,m,n,dp);
    }
};