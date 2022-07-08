// consecutive 1's not allowed
// dp[0][i] -> string ending at 1 of length i
	// d[1][i] -> string ending at 0 of length i
	ll countStrings(int n) {
	    ll mod=1e9+7;
	    vector<vector<ll>> dp(2,vector<ll>(n+1,0));
	    dp[0][0]=0;
	    dp[1][0]=0;
	    dp[0][1]=1;
	    dp[1][1]=1;
	    for(int i=2;i<=n;i++){
	        dp[0][i]=dp[1][i-1];
	        dp[1][i]=(dp[0][i-1]+dp[1][i-1])%mod;
	    }
	    return (dp[0][n]+dp[1][n])%mod;
	}