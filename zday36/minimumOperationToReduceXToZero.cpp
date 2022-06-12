// find maximum subarray of sum totalSum-x 
    int minOperations(vector<int>& nums, int x) {
        map<int,int> mp;// prefix sum and index
        mp[0]=-1;
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int target=totalSum-x;
        int maxLen=-1;
        int prefix=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            mp[prefix]=i;
            if(mp.find(prefix-target)==mp.end()){
            }
            else{
                maxLen=max(maxLen,i-mp[prefix-target]);
            }
        }
        if(maxLen==-1) return -1;
        return nums.size()-maxLen;
    }