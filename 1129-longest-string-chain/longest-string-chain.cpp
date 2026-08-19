class Solution {
public:
    int dp[1001][1001];
    bool checkPredecessor(string &pre, string &curr){
        int m = pre.length();
        int n = curr.length();
        if( m>=n || n-m!=1) return false;

        int i =0 , j=0;
        while(i<m && j<n){
            if(pre[i]==curr[j]){
                i++;
            }
            j++;
        }

        return i==m;
    }

    int solve(vector<string>& words,int i , int p){
        if(i==words.size()) return 0;

        if(p!=-1 && dp[p][i]!=-1){
            return dp[p][i];
        }
        int take=0;
        if(p==-1 ||checkPredecessor(words[p],words[i])){
            // if i is perideciser of p 
            take = 1 + solve(words,i+1,i);
        }
        int skip = solve(words,i+1,p);

        if(p!=-1){
            dp[p][i] = max(take,skip);
        }

        return max(take, skip);
    }

    static bool myfunction(string &word1,string &word2){
        return word1.length() < word2.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        memset(dp,-1,sizeof(dp));
        sort(begin(words),end(words),myfunction);

        return solve(words,0,-1);

    }   
};