int solve(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>j) return 1;
        if(dp[i][j]!=-1) return dp[i][j]; 
        return dp[i][j]= s[i]==s[j]?solve(i+1,j-1,s,dp):0;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
        // vector<vector<int>> dp(n,(vector<int>(n,-1)));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         ans+=solve(i,j,s,dp);
        //     }
        // }
        // return ans;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int dif=0;dif<n;dif++){ // length of string -1 i.e. dif between i and j
            for(int i=0,j=dif;j<n;i++,j++){
                if(dif==0) dp[i][j]=true;
                else if(dif==1){
                    dp[i][j]= (s[i]==s[j]);
                }
                else{
                    if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                    else dp[i][j]=false;
                }
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }