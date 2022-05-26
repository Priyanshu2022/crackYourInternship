// we are given a n length , we can cut it with x , y and z 
// we have to maximize cuts
int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i>=x && dp[i-x]!=-1){ // check if i>=x and can we cut i-x (dp[i-x])
                dp[i]=max(dp[i],1+dp[i-x]);
            }
            if(i>=y && dp[i-y]!=-1){
                dp[i]=max(dp[i],1+dp[i-y]);
            }
            if(i>=z && dp[i-z]!=-1){
                dp[i]=max(dp[i],1+dp[i-z]);
            }
        }
        return dp[n]<=0?0:dp[n];
    }