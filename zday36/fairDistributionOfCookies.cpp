void solve(int i,vector<int> &v,vector<int> &cookies,int k,int &ans){
        if(i==cookies.size()){
            ans=min(ans,*max_element(v.begin(),v.end()));
            return ;
        }
        for(int j=0;j<k;j++){
            v[j]+=cookies[i];
            solve(i+1,v,cookies,k,ans);
            v[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        vector<int> v(cookies.size(),0);
        solve(0,v,cookies,k,ans);
        return ans;
    }