string infixToPostfix(string s) {
        string ans="";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i]=='-' || s[i]=='+'){
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                while(st.top()=='*' || st.top()=='/' || st.top()=='^' || st.top()=='-' || st.top()=='+'){
                    ans+=st.top();
                    st.pop();
                    if(st.empty()) break;
                }
                st.push(s[i]);
            }
            else if(s[i]=='*' || s[i]=='/'){
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                while(st.top()=='^' || st.top()=='*' || st.top()=='/'){
                    ans+=st.top();
                    st.pop();
                    if(st.empty()) break;
                }
                st.push(s[i]);
            }
            else if(s[i]=='^'){
                if(st.empty()){
                    st.push(s[i]);
                    continue;
                }
                while(st.top()=='^'){
                    ans+=st.top();
                    st.pop();
                    if(st.empty()) break;
                }
                st.push(s[i]);
            }
            else ans+=s[i];
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }