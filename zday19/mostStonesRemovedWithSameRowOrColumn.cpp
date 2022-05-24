// most stones removed from same row or column
// make a dsu of n size
// run two for loops and if any of the row or column matches, union the indexes
// after that check , how many stones have same parent , that will imply then number of components
// removed stones = n-numberOfComponents(one stone of every componenet will remain)
int findPar(int node,vector<int> &parent){
    	if(node==parent[node]){
    		return node;
    	}
    	return parent[node]=findPar(parent[node],parent);
    }
    void Union(int u,int v,vector<int> &rank,vector<int> &parent){
    	u=findPar(u,parent);
    	v=findPar(v,parent);
    	if(rank[u]<rank[v]){
    		parent[u]=v;
    	}
    	else if(rank[v]<rank[u]){
    		parent[v]=u;
    	}
    	else{
    		parent[u]=v;
    		rank[v]++;
    	} 
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j,rank,parent);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(findPar(i,parent)==i) count++;
        }
        return n-count;
    }