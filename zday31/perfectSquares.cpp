// from a given position check , what is the minimum that we can go from here
// minimum number of squares to make n
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            for(int j=1;j*j<=i;j++){
                mini=min(mini,dp[i-j*j]);
            }
            dp[i]=mini+1;
        }
        return dp[n];
    }