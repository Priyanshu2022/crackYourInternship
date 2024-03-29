int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> ahead(2,0),cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j) cur[j]=max(-prices[i]-fee+ahead[0],ahead[1]);
                else cur[j]=max(prices[i]+ahead[1],ahead[0]);
            }
            ahead=cur;
        }
        return cur[1];
    }