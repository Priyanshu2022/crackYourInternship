// lexio smallest subseq of size k 
// we can remove n-k from the subarray
// if top is greater and we can remove element than remove
vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int elToRemove=n-k;
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && elToRemove && st.top()>nums[i]){
                st.pop();
                elToRemove--;
            }
            st.push(nums[i]);
        }
        
        // taking bottom k elements of stack
        vector<int> ans(k);
        while(st.size()!=k) st.pop();
        while(!st.empty()){
            ans[k-1]=st.top();
            st.pop();
            k--;
        }
        return ans;
    }