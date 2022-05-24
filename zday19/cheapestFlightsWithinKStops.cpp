// maintain stops array , which will contain stops required to reach
// priority will now also contain stops
// if distance is more than stored distance , still it can be answer 
// check if new stops is less than stored stops , if yes push

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> v[n];
        for(int i=0;i<flights.size();i++){
            v[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> distTo(n,INT_MAX);
        vector<int> stops(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > pq;
        stops[src]=0;
        pq.push({0,src,stops[src]});
        while(!pq.empty()){
            int dist=pq.top()[0];
            int node=pq.top()[1];
            int curStops=pq.top()[2];
            pq.pop();
            if(node==dst) return dist;
            if(curStops==k+1) continue;
            for(auto it:v[node]){
                int nextNode=it.first;
                int nextDist=it.second;
                int nextStops=curStops+1;
                if(distTo[nextNode]>dist+nextDist){
                    distTo[nextNode]=dist+nextDist;
                    stops[nextNode]=nextStops;
                    pq.push({distTo[nextNode],nextNode,nextStops});
                }
                else if(nextStops<stops[nextNode]){
                    pq.push({nextDist+dist,nextNode,nextStops});
                }
            }
        }
        return -1;
    }