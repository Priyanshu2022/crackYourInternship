long long int solve(int i,int j,string &s,vector<vector<long long int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]= (1+solve(i+1,j,s,dp)+solve(i,j-1,s,dp)+1000000007)%(1000000007);
        }
        else{
            return dp[i][j]= (solve(i+1,j,s,dp)+solve(i,j-1,s,dp)-solve(i+1,j-1,s,dp)+1000000007)%(1000000007);
        }
    }
    long long int  countPS(string str)
    {
       int i=0;
       int j=str.length()-1;
       vector<vector<long long int >> dp(str.length(),vector<long long int>(str.length(),-1));
       return solve(0,j,str,dp);
    }