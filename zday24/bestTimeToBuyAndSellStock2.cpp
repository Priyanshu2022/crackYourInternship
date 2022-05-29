// we are currently standing on a index we can buy are allowed to buy , or do nothing elsse sell or do nothing
    int solve(int index,bool buy,vector<int>& prices,vector<vector<int>> &dp){
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            return dp[index][buy]=max(-prices[index]+solve(index+1,0,prices,dp),solve(index+1,1,prices,dp));
        }
        else{
            return dp[index][buy]=max(prices[index]+solve(index+1,1,prices,dp),solve(index+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // // return solve(0,1,prices,dp);
        // dp[n][0]=dp[n][1]=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         if(j) dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
        //         else dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
        //     }
        // }
        // return dp[0][1];
        vector<int> ahead(2,0),cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j) cur[j]=max(-prices[i]+ahead[0],ahead[1]);
                else cur[j]=max(prices[i]+ahead[1],ahead[0]);
            }
            ahead=cur;
        }
        return cur[1];
    }