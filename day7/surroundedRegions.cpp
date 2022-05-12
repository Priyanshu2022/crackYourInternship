// surrounded regions
// means regions of O's not connected to edge , we have to mark them x
// first we will change all O in corner(edges) and it's connected O's to * 
// then change the remaining O's to X 
// then we will again change the * to O
void change(vector<vector<char>> &board,int x,int y){
        board[x][y]='*';
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(cx>=0 && cx<board.size() && cy>=0 && cy<board[0].size()){
                if(board[cx][cy]=='O') change(board,cx,cy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // first we will change all O in corner and it's connected O's to * 
        // then change the remaining O's to X 
        // then we will again change the * to O
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        change(board,i,j);
                    }
                }
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='*') board[i][j]='O';
            }
        }
        
    }