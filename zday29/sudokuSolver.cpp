bool isValid(int row,int col,char check,vector<vector<char>> &boards){
        for(int i=0;i<9;i++){
            if(boards[row][i]==check) return false;
            if(boards[i][col]==check) return false;
            if(boards[3*(row/3)+i/3][3*(col/3)+i%3]==check) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&boards){
        for(int i=0;i<boards.size();i++){
            for(int j=0;j<boards[0].size();j++){
                if(boards[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(i,j,c,boards)){
                            boards[i][j]=c;
                            if(solve(boards)==true){
                                return true;
                            }
                            else{
                                boards[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& boards) {
        bool temp=solve(boards);
    }