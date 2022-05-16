// minimum distance of every cell from any 0
// starting ans matrix with intmax and mark 0 element with zero
// store inexes of all zeroes in queue
// while q is not empty run the while loop
// and check if it can be updated update and push

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            if((i-1)>=0 && (ans[i][j]+1<ans[i-1][j])){
                ans[i-1][j]=ans[i][j]+1;
                q.push({i-1,j});
            }
            if((j-1)>=0 && (ans[i][j]+1<ans[i][j-1])){
                ans[i][j-1]=ans[i][j]+1;
                q.push({i,j-1});
            }
            if((i+1)<ans.size() && (ans[i][j]+1<ans[i+1][j])){
                ans[i+1][j]=ans[i][j]+1;
                q.push({i+1,j});
            }
            if((j+1)<ans[0].size() && (ans[i][j]+1<ans[i][j+1])){
                ans[i][j+1]=ans[i][j]+1;
                q.push({i,j+1});
            }
            q.pop();
        }
        return ans;
    }