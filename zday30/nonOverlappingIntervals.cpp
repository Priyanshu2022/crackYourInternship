int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int endTime=intervals[0][1];
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<endTime){
                ans++;
                endTime=min(endTime,intervals[i][1]);
            }
            else{
                endTime=intervals[i][1];
            }
        }
        return ans;
    }