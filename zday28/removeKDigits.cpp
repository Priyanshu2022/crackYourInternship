// giving tle
string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        int i=0;
        while(ans[i]=='0') i++;
        
        return ans.substr(i)==""?"0":ans.substr(i);
    }