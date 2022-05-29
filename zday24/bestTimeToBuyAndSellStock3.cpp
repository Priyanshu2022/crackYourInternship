// or n*4 (Buy sell buy sell)
    int solve(int index,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(index==prices.size()) return 0;
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        if(buy){
            return dp[index][buy][cap]=max(-prices[index]+solve(index+1,0,cap,prices,dp),solve(index+1,1,cap,prices,dp));
        }
        else{
            return dp[index][buy][cap]=max(+prices[index]+solve(index+1,1,cap-1,prices,dp),solve(index+1,0,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(0,1,2,prices,dp);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j) dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    else dp[i][j][k]=max(+prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                }
            }
        }
        return dp[0][1][2];
    }