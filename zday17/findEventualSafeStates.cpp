// find eventual safe state
// find state from where we can reach to terminal node (without entering in loop)
// find how many are in cycle using detect cycle in directed graph
bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &dfsVis,vector<bool>& present_cycle){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,dfsVis,present_cycle)){
                    return present_cycle[node]=true;
                }
            }
            else if(dfsVis[it]) return present_cycle[node]=true;
        }
        dfsVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        vector<bool> present_cycle(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,graph,vis,dfsVis,present_cycle);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!present_cycle[i]) ans.push_back(i);
        }
        return ans;
    }