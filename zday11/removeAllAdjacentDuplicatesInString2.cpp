// if k duplicates are together remove them
// stack of char ,int (count of that element)
// st.top has same char increment it's count
// if count==k st.pop()
// now form the ans string 
string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }
            else{
                auto prev=st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            if(st.top().second==k) st.pop();
        }
        string ans="";
        while(!st.empty()){
            auto cur=st.top();
            st.pop();
            while(cur.second--) ans+=cur.first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }