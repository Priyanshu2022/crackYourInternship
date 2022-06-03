// number of beutiful arrangements (perm[i] is divisible by i or i is divisible by perm[i])
int solve(int index,vector<int> &v){
        if(index==v.size()) return 1;
        int ans=0;
        for(int i=index;i<v.size();i++){
            if(v[i]%(index+1)==0 || (index+1)%v[i]==0){
                swap(v[index],v[i]);
                ans+=solve(index+1,v);
                swap(v[index],v[i]);
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=i+1;
        return solve(0,v);
    }