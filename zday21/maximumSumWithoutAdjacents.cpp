int solve(int *arr,int ind,vector<int> &dp){
	    if(ind<0) return 0;
	    if(dp[ind]!=-1) return dp[ind];
	    int pick=arr[ind]+solve(arr,ind-2,dp);
	    int notpick=solve(arr,ind-1,dp);
	    return dp[ind]=max(pick,notpick);
	}
	int findMaxSum(int *arr, int n) {
	   // vector<int> dp(n+1,-1);
	   // return solve(arr,n-1,dp
	   
	   // dp[0]=0;
	   // dp[1]=arr[0];
	   // for(int i=2;i<=n;i++){
	   //     dp[i]=max(dp[i-2]+arr[i-1],dp[i-1]);
	   // }
	   // return dp[n];
	   
	   int prev=arr[0];
	   int prev2=0;
	   for(int i=2;i<=n;i++){
	       int cur=max(prev2+arr[i-1],prev);
	       prev2=prev;
	       prev=cur;
	   }
	   return prev;
	   
	}