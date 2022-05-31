// giving tle
// at every floor there are two possibilities that the egg can break or not
    int solve(int f,int e,vector<vector<int>> &dp){
        if(f==1 || f==0) return f;
        if(e==1) return f;
        if(dp[f][e]!=-1) return dp[f][e];
        int ans=INT_MAX;
        for(int i=1;i<=f;i++){
            int moves=1+max(solve(i-1,e-1,dp),solve(f-i,e,dp));
            ans=min(ans,moves);
        }
        return dp[f][e]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }