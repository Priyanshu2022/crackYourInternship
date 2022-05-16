// rotten oranges 
// 0 -> empty  , 1-> fresh orange , 2-> rotten
// rotten , rottens in four directions
// push all rotten in queue
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0,count=0,minutes=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int size=q.size();
            count+=size;
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int cx=x+dx[i];
                    int cy=y+dy[i];
                    if(cx<0 || cx>=n || cy<0 || cy>=m || grid[cx][cy]!=1 ) continue;
                    grid[cx][cy]=2;
                    q.push({cx,cy});
                }
            }
            if(!q.empty()) minutes++;
        }
        return (total==count)?minutes:-1;
    }