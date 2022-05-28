// two subset with difference target 
    // s1-s2=target
    // totalSum-s2-s2=target
    int solve(int index,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(index<0){
            if(target==0) return 1;
            else return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake=solve(index-1,target,nums,dp);
        int take=0;
        if(target>=nums[index]) take=solve(index-1,target-nums[index],nums,dp);
        return dp[index][target]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(target>sum) return 0;
        if((sum-target)%2==1) return 0;
        vector<vector<int>> dp(n,vector<int> ((sum-target)/2+1,-1));
        return solve(n-1,(sum-target)/2,nums,dp);
    }