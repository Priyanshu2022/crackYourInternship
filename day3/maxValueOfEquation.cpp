// x is given in sorted order , and i<j 
    // therefore x[i]<x[j]
    // the equation becomes yi+yj+xj-xi=xj+yj+(yi-xi)
    // we can store yi-xj which is changing in priority queue
    // for current point we will check the maximum value of yi-xi
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++){
            while((!pq.empty())&&abs(pq.top().second-points[i][0])>k) pq.pop();
            if(!pq.empty()){
                ans=max(ans,points[i][0]+points[i][1]+pq.top().first);
            }
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }