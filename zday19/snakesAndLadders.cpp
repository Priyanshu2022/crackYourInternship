// snake and ladder of n^n blocks
// bfs algo
// maintain a visited and a queue
// find index positions of number in snake and ladder
pair<int,int> findPosition(int cx,int n){
        int i=n-((cx-1)/n) -1;
        int j=(i%2==n%2)?(n-((cx-1)%n)-1):(cx-1)%n;
        return {i,j};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        q.push(1);
        int steps=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int k=1;k<=6;k++){
                    int cx=x+k;
                    if(cx>n*n) break;
                    pair<int,int> p=findPosition(cx,n);
                    int i=p.first;
                    int j=p.second;
                    if(vis[i][j]) continue;
                    vis[i][j]=1;
                    if(board[i][j]==-1) q.push(cx);
                    else q.push(board[i][j]);
                }
            }
            steps++;
        }
        return -1;
    }
    