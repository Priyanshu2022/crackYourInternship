// ***********************
vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n+1,vector<int> (m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]+matrix[i][j]-dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }