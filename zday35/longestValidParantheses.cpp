int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
        int ans=0;
        int end=s.length();
        while(!st.empty()){
            int start=st.top();
            st.pop();
            ans=max(ans,end-start-1);
            end=start;
        }
        return max(ans,end);
    }