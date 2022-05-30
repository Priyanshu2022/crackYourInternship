// tc=> n*n*n
    // sc=> n*n 
    int solve(int i,int j,int arr[],vector<vector<int>> &dp){
        if(i==j) return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        // return solve(1,N-1,arr,dp);
        for(int i=0;i<N;i++) dp[i][i]=0;
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
    }