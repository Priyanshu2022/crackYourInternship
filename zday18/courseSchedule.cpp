// first task is dependent on the second one 
// detect cylce in directed graph
bool detectCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(detectCycle(it,adj,vis,dfsvis)==true) return true;
            }
            else if(dfsvis[it]) return true;
        }
        dfsvis[node]=0;
        return false;
    }
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) if(detectCycle(i,adj,vis,dfsvis)==true) return false;
        }
        return true;
	}