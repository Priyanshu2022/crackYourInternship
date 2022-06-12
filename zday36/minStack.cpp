// two approaches
    // first is to use two stacks or stack of pairs
    // where for each element we can store minimum till then
    
    // other one in one we can can calculate min with the help of prev element
    stack<int> st;
    int mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val>=mini) st.push(val);
            else{
                st.push(2*val-mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        int curr=st.top();
        st.pop();
        if(curr<=mini){
            mini=2*mini-curr;
        }
    }
    
    int top() {
        int curr=st.top();
        if(curr<mini) return mini;
        else return curr;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }