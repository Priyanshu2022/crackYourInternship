// steps by knight 
// minimum steps to react target -> bfs
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int ans=0;
	    int s1=KnightPos[0]-1;
	    int s2=KnightPos[1]-1;
	    int d1=TargetPos[0]-1;
	    int d2=TargetPos[1]-1;
	    vector<vector<int>> vis(N,vector<int>(N,-1));
	    if(s1==d1 && s2==d2) return 0;
	    queue<pair<int,int>> q;
	    q.push({s1,s2});
	    int dx[]={2,2,-2,-2,1,1,-1,-1};
	    int dy[]={1,-1,1,-1,2,-2,2,-2};
	    bool f=0;
	    while(!q.empty()){
	        ans++;
	        int size=q.size();
	        for(int i=0;i<size;i++){
	            pair<int,int> temp=q.front();
	            q.pop();
	            int x=temp.first;
	            int y=temp.second;
	            for(int i=0;i<8;i++){
	                int cx=x+dx[i];
	                int cy=y+dy[i];
	                if(cx<0 || cy<0 || cx>=N || cy>=N || vis[cx][cy]!=-1) continue;
	                if(cx==d1 && cy==d2) return ans;
	                vis[cx][cy]=1;
	                q.push({cx,cy});
	            }
	        }
	    }
	    return -1;
	}