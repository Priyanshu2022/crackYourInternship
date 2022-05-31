int findPar(int u,vector<int> &parent){
        if(u==parent[u]) return u;
        return parent[u]=findPar(parent[u],parent);
    }
    void Union(int u,int v,vector<int> &parent,vector<int> &rank){
        u=findPar(u,parent);
        v=findPar(v,parent);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        vector<int> rank(n+1,0);
        for(auto it:edges){
            if(findPar(it[0],parent)!=findPar(it[1],parent)){
                Union(it[0],it[1],parent,rank);
            }
            else return it;
        }
        vector<int> ans;
        return ans;
    }