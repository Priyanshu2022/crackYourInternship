// longest increasing path in matrix
// make a 2d dp and check for every index , maximum path we can get from here
int dfs(int x,int y,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(dp[x][y]) return dp[x][y];
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int ans=1;
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(cx<0 || cy<0 || cx>=matrix.size() || cy>=matrix[0].size()) continue;
            if(matrix[cx][cy]<=matrix[x][y]) continue;
            ans=max(ans,1+dfs(cx,cy,matrix,dp));
        }
        return dp[x][y]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }