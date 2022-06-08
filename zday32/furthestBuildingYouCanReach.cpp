int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i ;
        for( i=0;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            int dif=heights[i+1]-heights[i];
            if(bricks>=dif){
                pq.push(dif);
                bricks-=dif;
            }
            else if(ladders>0){
                if(!pq.empty()){
                    if(pq.top()>dif){
                        int maxBricksUsed=pq.top();
                        pq.pop();
                        bricks+=maxBricksUsed-dif;
                        pq.push(dif);
                    }
                }
                ladders--;
            }
            else break;
        }
        return i;
    }