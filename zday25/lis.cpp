int lengthOfLIS(vector<int>& nums) {
        // vector<int> dp(nums.size(),1);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
        vector<int> temp;// temporaty array is not the list , we are just storing elements
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }