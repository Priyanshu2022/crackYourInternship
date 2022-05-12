// for every element product of array except self
// if prod!=0 simply prod/nums[i]
// else check if zeros are present how many times
// if zeros are greater than or equal to two every answer will be 0
// else excet that 0 every answer will be 0
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod=1;
        int zeros=0;
        for(int i=0;i<nums.size();i++) prod*=nums[i],nums[i]==0?zeros++:1;
        if(prod!=0){
            for(int i=0;i<nums.size();i++){
                ans.push_back(prod/nums[i]);
            }
        }
        else{
            if(zeros>=2){
                for(int i=0;i<nums.size();i++) ans.push_back(0);
            }
            else{
                prod=1;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]!=0) prod*=nums[i];
                }
                for(int i=0;i<nums.size();i++){
                    if(nums[i]!=0){
                        ans.push_back(0);
                    }
                    else ans.push_back(prod);
                }
            }
        }
        return ans;
    }