// given a vector of strings , we have to tell largest number of stings in which there are atmost m 0's and n 1's
// we have two options to include the current string in ans or not 
    vector<vector<vector<int>>> dp;
    int countZeros(vector<string> &strs,int index){
        int count=0;
        for(int i=0;i<strs[index].size();i++){
            if(strs[index][i]=='0') count++;
        }
        return count;
    }
    int solve(int index,int m,int n,vector<string>& strs){
        if(index==strs.size()) return 0;
        if(dp[index][m][n]!=-1) return dp[index][m][n];
        int zeros=countZeros(strs,index);
        int ones=strs[index].size()-zeros;
        if(m>=zeros && n>=ones)
            return dp[index][m][n]=max(1+solve(index+1,m-zeros,n-ones,strs),solve(index+1,m,n,strs));
        else return dp[index][m][n]=solve(index+1,m,n,strs);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size()+1,vector<vector<int>>(m+1,vector<int> (n+1)));
        // return solve(0,m,n,strs);
        for(int i=1;i<=strs.size();i++){
            int zeros=countZeros(strs,i-1);
            int ones=strs[i-1].size()-zeros;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(j>=zeros && k>=ones)
                    dp[i][j][k]=max(1+dp[i-1][j-zeros][k-ones],dp[i-1][j][k]);
                    else dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        return dp[strs.size()][m][n];
    }