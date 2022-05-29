int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp){
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            return dp[index][buy]=max(-prices[index]+solve(index+1,0,prices,dp),solve(index+1,1,prices,dp));
        }
        else  return dp[index][buy]=max(+prices[index]+solve(index+2,1,prices,dp),solve(index+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        // return solve(0,1,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j) dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }