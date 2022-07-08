// count distinct in every window of size k
vector <int> countDistinct (int A[], int n, int k)
    {
        map<int,int> mp;
        vector<int> ans;
        int distinct=0;
        for(int i=0;i<k;i++) mp[A[i]]++;
        ans.push_back(mp.size());
        for(int i=k;i<n;i++){
            mp[A[i]]++;
            mp[A[i-k]]--;
            if(mp[A[i-k]]==0) mp.erase(A[i-k]);
            ans.push_back(mp.size());
        }
        return ans;
    }