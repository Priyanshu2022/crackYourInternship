// stack will store char and needed time
int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>> st;
        int ans=0;
        st.push({colors[0],neededTime[0]});
        for(int i=1;i<colors.size();i++){
            if(colors[i]==st.top().first){
                int prev=st.top().second;
                st.pop();
                int cur=neededTime[i];
                ans+=min(cur,prev);
                if(prev<cur){
                    st.push({colors[i],cur});
                }
                else st.push({colors[i],prev});
            }
            else st.push({colors[i],neededTime[i]});
        }
        return ans;
    }