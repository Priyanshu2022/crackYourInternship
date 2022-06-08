string reorganizeString(string s) {
        map<int,int> counts;
        for(auto it:s) counts[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:counts){
            pq.push({it.second,it.first});
        }
        pair<int,int> top1,top2;
        string ans="";
        while(!pq.empty()){
            top1=pq.top();
            pq.pop();
            ans+=(char)top1.second;
            if(!pq.empty()){
                top2=pq.top();
                pq.pop();
                ans+=(char)top2.second;
                if(top2.first>1) pq.push({top2.first-1,top2.second});
            }
            if(top1.first>1) pq.push({top1.first-1,top1.second});     
        }
        for(int i=0;i<ans.length()-1;i++){
            if(ans[i]==ans[i+1]) return "";
        }
        return ans;
    }