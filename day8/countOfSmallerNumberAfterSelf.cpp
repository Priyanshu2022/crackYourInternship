// count of smaller after self
// merge sort
// vector of pair with element and its index , as we will have to store the count in a index
// sort in descending order
void merge(vector<int> &ans,vector<pair<int,int>> &v,int l,int h,int m){
        vector<pair<int,int>> temp(h-l+1);
        int i=l;
        int j=m+1;
        int k=0;
        while(i<=m && j<=h){
            if(v[i].first>v[j].first){
                ans[v[i].second]+=h-j+1;
                temp[k++]=v[i++];
            }
            else temp[k++]=v[j++];
        }
        while(i<=m) temp[k++]=v[i++];
        while(j<=h) temp[k++]=v[j++];
        for(int t=l;t<=h;t++){
            v[t]=temp[t-l];
        }
    }
    void mergeSort(vector<int> &ans,vector<pair<int,int>> &v,int l,int h){
        if(l<h){
            int m=l+(h-l)/2;
            mergeSort(ans,v,l,m);
            mergeSort(ans,v,m+1,h);
            merge(ans,v,l,h,m);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});
        mergeSort(ans,v,0,v.size()-1);
        return ans;
    }