// maximal rectangle 
// given binary matrix
// find maximal rectangle of 1's
// 1 0 1 0 0 
// 1 0 1 1 1
// 1 1 1 1 1 
// 1 0 0 1 0
// move from row 1 to last (curRow) and calculate area if it was a histogram(it is like a histogram)
// add lower row one by one (if element is 0 curRow[j]=0 else curRow[j]++)
// return the maximum area
vector<int> nextSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
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
    int maxHistogram(vector<int>& heights) {
        int n=heights.size();
        vector<int> next;
        next=nextSmaller(heights,n);
        vector<int> prev;
        prev=prevSmaller(heights,n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(next[i]==-1) next[i]=n;
            ans=max(ans,heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') mat[i][j]=1;
            }
        }
        vector<int> curRow=mat[0];
        int maxAns=maxHistogram(curRow);
        for(int i=1;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    curRow[j]++;
                }
                else curRow[j]=0;
            }
            int curAns=maxHistogram(curRow);
            maxAns=max(curAns,maxAns);
        }
        return maxAns;
    }