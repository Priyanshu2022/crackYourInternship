vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int l=i+1;
                int h=n-1;
                int sum=0-nums[i];
                while(l<h){
                    if(nums[l]+nums[h]==sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);
                        l++;
                        h--;
                        while(l<h && nums[l]==nums[l-1]) l++;
                        while(l<h && nums[h]==nums[h+1]) h--;
                    }
                    else if(nums[l]+nums[h]>sum) h--;
                    else l++;
                }
            }
        }
        return ans;
    }