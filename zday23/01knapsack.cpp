int solve(int index,int w,int wt[],int val[],vector<vector<int>> &dp){
        if(index==0){
            if(wt[index]<=w) return val[index];
            else return 0;
        }
        if(dp[index][w]!=-1) return dp[index][w];
        int notTake=solve(index-1,w,wt,val,dp);
        int take=INT_MIN;
        if(w>=wt[index]) take=val[index]+solve(index-1,w-wt[index],wt,val,dp);
        return dp[index][w]=max(take,notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,0));
    //   return solve(n-1,W,wt,val,dp);
        for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
        for(int i=1;i<n;i++){
            for(int j=1;j<=W;j++){
                int notTake=dp[i-1][j];
                int take=INT_MIN;
                if(j>=wt[i]) take=val[i]+dp[i-1][j-wt[i]];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[n-1][W];
    }