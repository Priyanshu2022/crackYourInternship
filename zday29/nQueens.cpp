bool isValid(int row,int col,vector<string> &board,int n){
        int i=row;
        while(i>=0){
            if(board[i][col]=='Q') return false;
            i--;
        }
        i=row;
        int j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i>=0 && j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> &board,int n,int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(row,i,board,n)){
                board[row][i]='Q';
                solve(ans,board,n,row+1);
                board[row][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(ans,board,n,0);
        return ans;
    }