bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum=sum/2;
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum+1,false));
        for(int i=0;i<=sum;i++) dp[0][i]=false;
        for(int i=0;i<nums.size();i++) dp[i][0]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(j>=nums[i]) take=dp[i-1][j-nums[i]];
                dp[i][j]=take||notTake;
            }
        }
        return dp[nums.size()-1][sum];
    }