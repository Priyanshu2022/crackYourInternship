// after reaching n-1,n-1 , we can again go to 0,0
    // it is same as two person goint to end
    // i1,j1,i2,j2 => i1+j1=i2+j2  =>  dp[i][j1][j2]
    int solve(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        int i1=i;
        int i2=i1+j1-j2;
        if(i>=grid.size() || i2>=grid.size() || j1>=grid[0].size() || j2>=grid[0].size()) return -1e8;
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1) return INT_MIN;
        if(i1==grid.size()-1 && j1==grid.size()-1) return grid[i][j1];
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        if(j1==j2 && i1==i2) ans+=grid[i][j1];
        else ans+=grid[i1][j1]+grid[i2][j2];
        int value=max(solve(i+1,j1,j2,grid,dp),solve(i+1,j1,j2+1,grid,dp));
        value=max(value,solve(i,j1+1,j2+1,grid,dp));
        value=max(value,solve(i,j1+1,j2,grid,dp));
        ans+=value;
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,solve(0,0,0,grid,dp));
    }