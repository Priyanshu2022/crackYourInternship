// first and last are adjacent
// first and last will not be together
    // leave the last and then leave the first , max of both
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size()-1;i++){
            int cur=max(prev2+nums[i],prev);
            prev2=prev;
            prev=cur;
        }
        int ans1=prev;
        
        prev=nums[1];
        prev2=0;
        for(int i=2;i<nums.size();i++){
            int cur=max(prev2+nums[i],prev);
            prev2=prev;
            prev=cur;
        }
        int ans2=prev;
        
        return max(ans1,ans2);
    }