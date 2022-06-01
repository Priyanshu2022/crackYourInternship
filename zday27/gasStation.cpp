int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance=0;
        int start=0;
        int deficit=0;
        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficit+=balance;
                balance=0;
                start=i+1;
            }
        }
        return balance+deficit>=0?start:-1;
    }