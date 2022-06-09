// only 6 cells are changing => 2^6=64 combinations , means pattern will repeat
vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        set<vector<int>> st;
        int size=0;
        for(int i=0;i<n;i++){ // this will not run n time , it will break when , we will find the pattern
            vector<int> temp(8,0);
            for(int i=1;i<7;i++){
                temp[i]= (cells[i-1]==cells[i+1]);
            }
            if(st.find(temp)!=st.end()) break;
            cells=temp;
            st.insert(temp);
            size++;
        }
        for(auto it:cells) cout<<it<<" ";
        n=n%size;
        for(int i=0;i<n;i++){
            vector<int> temp(8,0);
            for(int j=1;j<7;j++){
                temp[j]= cells[j-1]==cells[j+1];
            }
            cells=temp;
        }
        return cells;
    }