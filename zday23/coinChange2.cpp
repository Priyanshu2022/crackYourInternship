int solve(int index,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(index==0){
            if(amount%coins[index]==0) return 1;
            else return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=solve(index-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[index]) take=solve(index,amount-coins[index],coins,dp);
        return dp[index][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // return solve(n-1,amount,coins,dp);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake=dp[i-1][j];
                int take=0;
                if(j>=coins[i]) take=dp[i][j-coins[i]];
                dp[i][j]=take+notTake;
            }
        }
        return dp[n-1][amount];
    }