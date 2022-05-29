int solve(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return solve(i-1,j-1,word1,word2,dp);
        int insertion=1+solve(i,j-1,word1,word2,dp);
        int deletion=1+solve(i-1,j,word1,word2,dp);
        int replace=1+solve(i-1,j-1,word1,word2,dp);
        return dp[i][j]=min(insertion,min(deletion,replace));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,word1,word2,dp);
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insertion=1+dp[i][j-1];
                    int deletion=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(insertion,min(deletion,replace));
                }
            }
        }
        return dp[n][m];
    }