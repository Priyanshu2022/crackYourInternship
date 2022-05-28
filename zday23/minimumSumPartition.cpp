// last row stores is using all elements we can make a sum or not
	int minDifference(int arr[], int n){ 
	    int sum=accumulate(arr,arr+n,0);
	    vector<vector<bool>> dp(n,vector<bool>(sum,false));
	    for(int i=0;i<n;i++) dp[i][0]=true;
	    for(int i=1;i<n;i++){
	        for(int j=1;j<=sum;j++){
	            bool notTake=dp[i-1][j];
	            bool take=false;
	            if(j>=arr[i]) take=dp[i-1][j-arr[i]];
	            dp[i][j]=take||notTake;
	        }
	    }
	    int ans=INT_MAX;
	    for(int i=0;i<=sum;i++){
	        if(dp[n-1][i]==true){
    	        int s1=i;
    	        int s2=sum-s1;
    	        ans=min(ans,abs(s1-s2));
	        }
	    }
	    return ans;
	} 