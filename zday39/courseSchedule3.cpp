static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[1]<v2[1]) return true;
        else if(v1[1]>v2[1]) return false;
        return v1[0]<v2[0];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> pq;
        int time=0;
        for(int i=0;i<courses.size();i++){
            if(time+courses[i][0]<=courses[i][1]){
                pq.push(courses[i][0]);
                time+=courses[i][0];
            }
            else{
                if(!pq.empty() && pq.top()>=courses[i][0]){
                    time-=pq.top()-courses[i][0];
                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }
        return pq.size();
    }