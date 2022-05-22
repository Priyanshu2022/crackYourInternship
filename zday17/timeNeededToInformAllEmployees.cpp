// minutes needed to inform parent +   max time needed by childrens
    int dfs(vector<int> adj[],int node,vector<int> &informTime){
        int maxi=0;
        for(auto it:adj[node]){
            maxi=max(maxi,dfs(adj,it,informTime));
        }
        return maxi+informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        return dfs(adj,headID,informTime);
    }