// The span of the stock's price today is defined as the maximum number of consecutive days 
// (starting from today and going backward) for which the stock price was less than or equal to today's price.
// For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock 
// spans would be [1,1,1,2,1,4,6]
// we wil simply check if stack is empty means there is no next greater in left so i+1
// else i-st.top().second (index of next greater  in  left)
StockSpanner() {
        
    }
    int i=0;
    stack<pair<int,int>> st;
    int next(int price) {
        while(!st.empty() && st.top().first<=price) st.pop();
        int ans;
        if(st.empty()) ans=i+1;
        else ans=i-st.top().second;
        st.push({price,i});
        i++;
        return ans;
    }