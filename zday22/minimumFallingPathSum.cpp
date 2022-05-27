int solve(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || j>=matrix.size()) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,matrix,dp);
        int ld=solve(i-1,j-1,matrix,dp);
        int rd=solve(i-1,j+1,matrix,dp);
        return dp[i][j]=matrix[i][j]+min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,solve(n-1,i,matrix,dp));
        // }
        // return ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) dp[i][j]=matrix[i][j];
                else{
                    int up=1e9;
                    int ld=1e9;
                    int rd=1e9;
                    up=dp[i-1][j];
                    if(j>0) ld=dp[i-1][j-1];
                    if(j<n-1) rd=dp[i-1][j+1];
                    dp[i][j]=matrix[i][j]+min(up,min(ld,rd));
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }