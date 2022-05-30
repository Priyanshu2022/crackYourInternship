// dp will be of i , j , what we want (true or false) and it will store no of ways
    int solve(int i,int j,bool isTrue,string &s,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways=0;
        for(int ind=i+1;ind<j;ind+=2){
            int lT=solve(i,ind-1,1,s,dp);
            int lF=solve(i,ind-1,0,s,dp);
            int rT=solve(ind+1,j,1,s,dp);
            int rF=solve(ind+1,j,0,s,dp);
            if(s[ind]=='&'){
                if(isTrue) ways+=(rT*lT)%1003;
                else ways+=(lF*rF+lF*rT+lT*rF)%1003;
            }
            else if(s[ind]=='|'){
                if(isTrue) ways+=(lT*rT+lF*rT+lT*rF)%1003;
                else ways+=(lF*rF)%1003;
            }
            else{
                if(isTrue) ways+=(lT*rF+lF*rT)%1003;
                else ways+=(lF*rF+lT*rT)%1003;
            }
        }
        return dp[i][j][isTrue]=ways%1003;
    }
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N,vector<vector<int>> (N,vector<int>(2,-1)));
        return solve(0,N-1,1,S,dp);
    }