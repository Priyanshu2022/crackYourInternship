// given connection , we have to make them connected
void dfs(int node,vector<int> &vis,vector<int> adj[]){
        if(vis[node]) return ;
        vis[node]=1;
        for(auto it:adj[node]){
            dfs(it,vis,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<int> adj[n];
        int m=connections.size();
        if(m<n-1) return -1;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][1]].push_back(connections[i][0]);
            adj[connections[i][0]].push_back(connections[i][1]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans-1;
    }