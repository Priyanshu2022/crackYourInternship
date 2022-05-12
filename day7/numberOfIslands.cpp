  // number of islands
  // ["1","1","1","1","0"],
  // ["1","1","0","1","0"],
  // ["1","1","0","0","0"],
  // ["0","0","0","0","0"]
// check every element if it's one and not visited
// run dfs on it 
void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return; 
        if(grid[i][j]=='0') return;
        if(vis[i][j]!=-1) return ;
        vis[i][j]=1;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }