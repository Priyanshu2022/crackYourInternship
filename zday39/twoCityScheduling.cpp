// two city scheduling
static bool cmp(vector<int> &v1,vector<int> &v2){
        return v1[0]-v1[1]<v2[0]-v2[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int ans=0;
        for(int i=0;i<costs.size();i++){
            if(i<costs.size()/2) ans+=costs[i][0];
            else ans+=costs[i][1];
        }
        return ans;
    }

// Allright so whenever you call a non-static member function of class outside of a class you do something like this,
// obj a;
// a.compare(b); //2 parameters are required - a & b
// i.e. for non-static member functions, we have to provide an extra parameter for the implicit this.

// Whereas making a member function static allows this call,
// Solution:: compare(b); //Just 1 parameter required

// Similarly, since the code for sort will be executed outside your class, we've to declare it static else the first parameter in your comparator function will be used as the implicit first parameter for this in non-static member functions.