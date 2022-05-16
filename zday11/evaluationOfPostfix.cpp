// evaluation of postfix(reverse polish notation)
// string to number -> stoi()
int evaluatePostfix(string exp)
    {
        stack<int> st;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='*'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(first*second);
        }
        else if(exp[i]=='/'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second/first);
        }
        else if(exp[i]=='+'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(first+second);
        }
        else if(exp[i]=='-'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second-first);
        }
        else st.push(exp[i]-'0');
    }
    return st.top();
    }