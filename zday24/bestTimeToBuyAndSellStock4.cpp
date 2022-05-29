int solve(int i,int tranNo,vector<int>& prices,int n,int k,vector<vector<int>> &dp){
        if(i==n || tranNo==2*k) return 0;
        if(dp[i][tranNo]!=-1) return dp[i][tranNo];
        if(tranNo%2==0) return dp[i][tranNo]=max(-prices[i]+solve(i+1,tranNo+1,prices,n,k,dp),solve(i+1,tranNo,prices,n,k,dp));
        else return dp[i][tranNo]=max(+prices[i]+solve(i+1,tranNo+1,prices,n,k,dp),solve(i+1,tranNo,prices,n,k,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2*k,-1));
        // return solve(0,0,prices,n,k,dp);
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j%2==0) dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                else dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
        
        // int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         for(int l=1;l<=k;l++){
        //             if(j) dp[i][j][l]=max(-prices[i]+dp[i+1][0][l],dp[i+1][1][l]);
        //             else dp[i][j][l]=max(+prices[i]+dp[i+1][1][l-1],dp[i+1][0][l]);
        //         }
        //     }
        // }
        // return dp[0][1][k];
    }
