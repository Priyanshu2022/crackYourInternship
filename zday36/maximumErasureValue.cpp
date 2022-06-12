int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        int sum=0;
        int left=0;
        int right=0;
        while(right<nums.size()){
            while(mp.find(nums[right])!=mp.end()){
                mp.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            mp[nums[right]]=right;
            sum+=nums[right];
            ans=max(ans,sum);
            right++;
        }
        return ans;
    }