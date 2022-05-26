// when number is even , number of set bit is same as number of set bit in half of the number
    // when number is odd , nuber of set bit is prev +1 -> prev=(i-1)/2+1 ==>i/2+1(for odd)
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i&1){
                // dp[i]=dp[i/2]+1;
                dp[i]=dp[i-1]+1;
            }
            else dp[i]=dp[i/2];
        }
        return dp;
    }