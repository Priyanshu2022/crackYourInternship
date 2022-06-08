// binary search on time , for each time run dfs
    bool dfs(int x,int y,int t,vector<vector<int>> &grid,vector<vector<int>> &vis){
        if(grid[x][y]>t) return false;
        if(x==grid.size()-1 && y==grid.size()-1) return true;
        vis[x][y]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(cx<0 || cy<0 || cx>=grid.size() || cy>=grid.size() || vis[cx][cy]) continue;
            if(dfs(cx,cy,t,grid,vis)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int low=0;
        int high=50*50;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            vector<vector<int>> vis(n,vector<int>(n,0));
            if(dfs(0,0,mid,grid,vis)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }