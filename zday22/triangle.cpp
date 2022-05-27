int solve(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(solve(i+1,j,triangle,dp),solve(i+1,j+1,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        // return solve(0,0,triangle,dp);
        int n=triangle.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                if(i==n-1) dp[i][j]=triangle[i][j];
                else{
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }