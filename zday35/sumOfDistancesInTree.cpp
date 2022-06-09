// dfs1 is to mark the count and calculate the answer for root node
// dfs is to re-root the roots to calculate the anwer for all nodes
// count is no of nodes in its substree
void dfs1(int i,int parent,vector<int> &count,vector<int> &res,vector<vector<int>> &v){
        for(auto it:v[i]){
            if(it==parent) continue;
            dfs1(it,i,count,res,v);
            count[i]+=count[it];
            res[i]+=res[it]+count[it];
        }
        count[i]++;
    }
    void dfs(int i,int parent,int n,vector<int> &count,vector<int> &res,vector<vector<int>> &v){
        for(auto it:v[i]){
            if(it==parent) continue;
            res[it]=res[i]-count[it]+n-count[it];
            dfs(it,i,n,count,res,v);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> count(n,0);
        vector<int> res(n,0);
        vector<vector<int>> v(n);
        for(auto it:edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        dfs1(0,-1,count,res,v);
        dfs(0,-1,n,count,res,v);
        return res;
    }