// numbers are from 1 to n go to nums[nums[i]-1] and make it negative if it is not , and if it is negative push nums[i]
// in vector as it make us go to the same index again 
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            if(nums[n-1]<0) ans.push_back(n);
            else nums[n-1]*=-1;
        }
        return ans;
    }