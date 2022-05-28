// try to pick lengths and sum them up to make the given n 
    // unbounded knapsack
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,0));
        for(int i=0;i<=W;i++) dp[0][i]=(i/wt[0])*val[0];
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int notTake=dp[i-1][j];
                int take=INT_MIN;
                if(j>=wt[i]) take=val[i]+dp[i][j-wt[i]];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[N-1][W];
    }
    int cutRod(int price[], int n) {
        int wt[n];
        for(int i=0;i<n;i++) wt[i]=i+1;
        return knapSack(n,n,price,wt);
    }