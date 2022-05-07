// bfs
bool bfs(vector<vector<char>>& board,int i,int j,string word,int index,vector<vector<int>> &vis){
        if(index==word.length()) return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0) return false;
        if(board[i][j]!=word[index]) return false;
        if(vis[i][j]) return false;
        else vis[i][j]=1;
        if(bfs(board,i+1,j,word,index+1,vis) || bfs(board,i-1,j,word,index+1,vis) || bfs(board,i,j+1,word,index+1,vis) || bfs(board,i,j-1,word,index+1,vis)) return true;
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(bfs(board,i,j,word,0,vis)) return true;
            }
        }
        return false;
    }