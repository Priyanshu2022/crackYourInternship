int minDeletions(string s) {
        unordered_map<char,int> mp;
        priority_queue<int> pq;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        int ans=0;
        while(!pq.empty()){
            int first=pq.top();
            pq.pop();
            if(pq.empty()) break;
            int second=pq.top();
            if(first==second){
                ans++;
                first--;
                if(first) pq.push(first);
            }
        }
        return ans;
    }