static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0]) return v1[1]<v2[1];
        return v1[0]>v2[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans;
        for(auto it:people){
            ans.insert(ans.begin()+it[1],it); // elements before this are greater 
        }
        return ans;
    }