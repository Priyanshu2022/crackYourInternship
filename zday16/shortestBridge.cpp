// find any one and run dfs on it while storing the nodes then break
    // now from the nodes in queue run bfs and find minimum distance
    void dfs(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &vis,queue<pair<int,int>> &q){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || vis[x][y]!=-1 || grid[x][y]==0) return;
        vis[x][y]=1;
        q.push({x,y});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            dfs(cx,cy,grid,vis,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        bool f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,q);
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        int dist=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            dist++;
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> temp=q.front();
                int x=temp.first;
                int y=temp.second;
                q.pop();
                for(int j=0;j<4;j++){
                    int cx=x+dx[j];
                    int cy=y+dy[j];
                    if(cx<0 || cy<0 || cx>=n || cy>=m || vis[cx][cy]==1) continue;
                    vis[cx][cy]=1;
                    if(grid[cx][cy]==1) return dist-1;
                    q.push({cx,cy});
                }
            }
        }
        return -1;
    }