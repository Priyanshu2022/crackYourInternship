int solve(int index,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(index==0){
            if(amount%coins[index]==0) return amount/coins[index];
            else return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=solve(index-1,amount,coins,dp);
        int take=1e9;
        if(amount>=coins[index]) take=1+solve(index,amount-coins[index],coins,dp);
        return dp[index][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // int ans=solve(n-1,amount,coins,dp);
        // if(ans==1e9) return -1;
        // else return ans;
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notTake=dp[i-1][j];
                int take=1e9;
                if(j>=coins[i]) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,notTake);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }