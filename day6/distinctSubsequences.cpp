// rabbbit rabbit
// number of times 2nd string occur as a subsequence in 1st string
// i=n-1, j=m-1
// if s[i]==t[j] there are two options either we can consider a[j] as occurence or look for anotheer
// therefore i-1 j-1(included) + i-1 j(not included)
// else i-1 j(cannot include)
int solve(string &s ,string &t,int index1,int index2,vector<vector<int>> &dp){
        if(index2<0) return 1;
        if(index1<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1]==t[index2]){
            return dp[index1][index2]=(solve(s,t,index1-1,index2-1,dp)+solve(s,t,index1-1,index2,dp));
        }
        else return dp[index1][index2]=solve(s,t,index1-1,index2,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return solve(s,t,s.length()-1,t.length()-1,dp);
    }