// given two jugs , want to know weather it is possible measure target sum
// we are effectively having one judge with capacity equal to it's sum of both jar's
// we can basically increase the water by x, y and decrease by y
// bfs -> tc=(total capacity)+e
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity;
        int y=jug2Capacity;
        int z=targetCapacity;
        if(z>x+y) return false;
        map<int,int> vis;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int dx[]={x,-x,y,-y};
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(a==z) return true;
            for(int i=0;i<4;i++){
                int ca=a+dx[i];
                if(ca<0 || ca>x+y || vis.find(ca)!=vis.end()) continue;
                vis[ca]=1;
                q.push(ca);
            }
        }
        return false;
    }