int solve(int index,int w,int wt[],int val[],vector<vector<int>> &dp){
        if(index==0){
            return (w/wt[index])*val[index];
        }
        if(dp[index][w]!=-1) return dp[index][w];
        int notTake=solve(index-1,w,wt,val,dp);
        int take=INT_MIN;
        if(w>=wt[index]) take=val[index]+solve(index,w-wt[index],wt,val,dp);
        return dp[index][w]=max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,0));
        // return solve(N-1,W,wt,val,dp);
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