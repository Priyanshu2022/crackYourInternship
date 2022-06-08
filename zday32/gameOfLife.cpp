// if cell becoming dead replace with -1
    // if cell becoming live replace with 2
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dx[]={0,0,1,1,1,-1,-1,-1};
        int dy[]={1,-1,1,-1,0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int countOne=0;
                for(int k=0;k<8;k++){
                    int cx=i+dx[k];
                    int cy=j+dy[k];
                    if(cx<0 || cy<0 || cx>=n || cy>=m) continue;
                    if(abs(board[cx][cy])==1) countOne++;
                }
                if(board[i][j]==0){
                    if(countOne==3){
                        board[i][j]=2;
                    }
                }
                else if(board[i][j]==1){
                    if(countOne<2 || countOne>3){
                        board[i][j]=-1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-1) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
    }