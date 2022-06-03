int dfs(int i,int j,int zero,vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1) return 0;
        if(grid[i][j]==2) return zero==-1?1:0;
        int totalPath=0;
        grid[i][j]=-1;
        zero--;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            totalPath+=dfs(i+dx[k],j+dy[k],zero,grid);
        }
        grid[i][j]=0;
        zero++;
        return totalPath;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x,y;
        int zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) zero++;
                else if(grid[i][j]==1) x=i,y=j;
            }
        }
        return dfs(x,y,zero,grid);
    }