// minimum cost of ropes 
long long minCost(long long arr[], long long n) {
        long long ans=0;
        priority_queue<long long ,vector<long long >,greater<long long >> pq;
        for(int i=0;i<n;i++) pq.push(arr[i]);
        while(!pq.empty()){
            long long first=pq.top();
            pq.pop();
            if(pq.empty()) break;
            long long second=pq.top();
            pq.pop();
            ans+=first+second;
            pq.push(first+second);
        }
        return ans;
    }