// we will store in temp , the score we will get after deleting that element
    int deleteAndEarn(vector<int>& nums) {
        vector<int> temp(1e4+1,0);
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]+=nums[i];
        }
        int prev=temp[0];
        int prev2=0;
        for(int i=1;i<temp.size();i++){
            int cur=max(prev,prev2+temp[i]);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }