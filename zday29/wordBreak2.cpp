void solve(int index,string &s,unordered_map<string,int> mp,vector<vector<string>> &ans,vector<string> &ds){
        if(index==s.length()) {
            ans.push_back(ds);
            return ;
        }
        string temp;
        for(int i=index;i<s.length();i++){
            temp+=s[i];
            if(mp.find(temp)!=mp.end()){
                ds.push_back(temp);
                solve(i+1,s,mp,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> ans;
        vector<string> ds;
        unordered_map<string,int> mp;
        for(auto it:wordDict) mp[it]++;
        solve(0,s,mp,ans,ds);
        vector<string> finalAns;
        for(auto it:ans){
            string temp="";
            for(auto cur:it){
                if(temp.length()==0) temp+=cur;
                else{
                    temp+=" ";
                    temp+=cur;
                }
            }
            finalAns.push_back(temp);
        }
        return finalAns;
    }