// sum of minimum of every subarray
// iterate over every element and suppose it's minimum of a subarray
// but question of how many subarray
// we will calculate next smaller and prev smaller
// then we will calculate elements in left of that element then elemenst in right of that element
// total subarrays (left+1)*(right+1)
// cost v[i]*tota subarryas with that element minimum
// if have two equal element in the array ,then we will count subarrays twice
// therefore mark either in next smaller or prev smaller greater than or equal to in heights[st.top()]>=heights[i]
vector<int> nextSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=arr[i];
        vector<int> next=nextSmaller(v,n);
        vector<int> prev=prevSmaller(v,n);
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long int right=next[i]-i-1; 
            long long int left=i-prev[i]-1;
            if(next[i]==-1) right=n-i-1;
            if(prev[i]==-1) left=i;
            ans=(ans%mod+v[i]*(left+1)*(right+1))%mod;
        }
        return ans;
    }