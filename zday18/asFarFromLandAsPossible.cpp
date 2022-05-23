// given matrix of 0 and 1 , find a zero such that distance of that from the nearest one is maximised
// go from 1 to zero , put all one in queue
// and run dfs
int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        bool one=false,zero=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) one =true;
                if(grid[i][j]==0) zero=true;
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        if(!one || !zero ) return -1;
        int ans=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int cx=x+dx[i];
                    int cy=y+dy[i];
                    if(cx<0 || cy<0 || cx>=grid.size() || cy>=grid[0].size() || grid[cx][cy]==1) continue;
                    grid[cx][cy]=1;
                    q.push({cx,cy});
                }
            }
            if(!q.empty()) ans++;
        }
        return ans;
    }