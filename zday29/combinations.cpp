// generate all possible combinations of k numbers
void solve(int n,int k,vector<vector<int>> &ans,vector<int> &ds){
        if(k==0){
            ans.push_back(ds);
            return ;
        }
        if(n==0) return ;
        
        ds.push_back(n);
        solve(n-1,k-1,ans,ds);
        ds.pop_back();
        
        solve(n-1,k,ans,ds);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(n,k,ans,ds);
        return ans;
    }