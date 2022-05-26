// can't rob continuout houses
int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int cur=max(prev2+nums[i],prev);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }