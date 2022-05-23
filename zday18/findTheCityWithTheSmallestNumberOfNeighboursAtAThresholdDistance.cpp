// find the city , from which we can visit smallest number of cities under the given distance
// floyyd warshall -> all pair shortes path
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++){ // k is our pivot
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && (dist[i][k]+dist[k][j])<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int ans;
        int cityCount=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) count++;
            }
            if(cityCount>=count){
                ans=i;
                cityCount=count;
            }
        }
        return ans;
    }