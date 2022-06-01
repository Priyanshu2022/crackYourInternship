// run dfs
void dfs(int node,unordered_map<int,vector<int>> &mp,set<int> &vis,vector<int> &ans){
        if(vis.find(node)!=vis.end()) return ;
        ans.push_back(node);
        vis.insert(node);
        for(auto it:mp[node]){
            dfs(it,mp,vis,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        for(auto it:adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int start;
        for(auto it:mp){
            if(it.second.size()==1){
                start=it.first;
                break;
            }
        }
        set<int> vis;
        vector<int> ans;
        dfs(start,mp,vis,ans);
        
        return ans;
    }