// given a binary 2d binary matrix
// we can change atmost a zero to one and get the largest size of island
// firstly change all island to it's id and store <id , area> in the map
// then again run 2 for loops , check if it is zero and converting it will give us how much area 
void dfs(int x,int y,vector<vector<int>> &grid,int id,int &count){
        if(x<0 || y<0 || x>=grid.size() || y>=grid.size()) return ;
        if(grid[x][y]>1 || grid[x][y]==0) return ;
        count++;
        grid[x][y]=id;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            dfs(cx,cy,grid,id,count);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        //  id  area
        map<int,int> mp;
        int n=grid.size();
        int id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(i,j,grid,id,count);
                    mp[id]=count;
                    id++;
                }
            }
        }
        int ans=INT_MIN;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int sum=0;
                    set<int> s;
                    for(int k=0;k<4;k++){
                        int cx=i+dx[k];
                        int cy=j+dy[k];
                        if(cx<0 || cy<0 || cx>=n || cy>=n || grid[cx][cy]==0) continue;
                        if(s.find(grid[cx][cy])!=s.end()) continue;
                        s.insert(grid[cx][cy]);
                        sum+=mp[grid[cx][cy]];
                    }
                    ans=max(ans,sum+1);
                }
            }
        }
        return ans==INT_MIN?n*n:ans;
    }