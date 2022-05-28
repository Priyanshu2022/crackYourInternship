int solve(int index,int sum,int arr[],vector<vector<int>> &dp){
	    if(index<0){
	        if(sum==0) return 1;
	        else return 0;
	    }
	    if(dp[index][sum]!=-1) return dp[index][sum];
	    int notPick=solve(index-1,sum,arr,dp);
	    int pick=0;
	    if(arr[index]<=sum) pick=solve(index-1,sum-arr[index],arr,dp);
	    return dp[index][sum]=(pick+notPick)%1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
        // for(int i=0;i<n;i++) dp[i][0]=1;
        // if(arr[0]<=sum) dp[0][arr[0]]=1;
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=sum;j++){
        //         int notPick=dp[i-1][j];
        //         int pick=0;
        //         if(j>=arr[i]) pick=dp[i-1][j-arr[i]];
        //         dp[i][j]=pick+notPick;
        //     }
        // }
        // return dp[n-1][sum];
	}