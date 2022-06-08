// push all stations before current , in max heap
    // take if distance is less than target
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0;
        int cur=startFuel;
        int ans=0;
        priority_queue<int> pq;
        while(cur<target){
            while(i<stations.size() && stations[i][0]<=cur) pq.push(stations[i++][1]);
            if(pq.empty()) return -1;
            cur+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }