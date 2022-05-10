// there are two choice if we have remaining spaces greater than current word lenght
// then we can put it there or in next line
// index here is current word's index
int dp[501][2001];
    int solve(int index,int rem,vector<int> &arr,int &k){
        if(index==arr.size()) return 0;
        if(dp[index][rem]!=-1) return dp[index][rem];
        int ans;
        if(arr[index]>rem){
            ans=(rem+1)*(rem+1)+solve(index+1,k-arr[index]-1,arr,k);
        }
        else{
            ans=min((rem+1)*(rem+1)+solve(index+1,k-arr[index]-1,arr,k),solve(index+1,rem-arr[index]-1,arr,k));
        }
        dp[index][rem]=ans;
        return ans;
    }
    int solveWordWrap(vector<int>arr, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return solve(0,k,arr,k);
    } 