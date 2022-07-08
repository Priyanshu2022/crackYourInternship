// making the element minimum is optimal
    bool checkPossibility(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count++;
                if(i==1){
                    nums[i-1]=nums[i];
                    continue;
                }
                if(nums[i-2]>nums[i]) nums[i]=nums[i-1];
                else nums[i-1]=nums[i];
            }
        }
        return count<=1;
    }