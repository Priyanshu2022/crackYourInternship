vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j=i+1;j<n-2;j++){
                    if(j==i+1 || nums[j]!=nums[j-1]){
                        cout<<j<<endl;
                        int l=j+1;
                        int h=n-1;
                        int sum=target-nums[i]-nums[j];
                        while(l<h){
                            if(nums[l]+nums[h]==sum){
                                ans.push_back({nums[i],nums[j],nums[l],nums[h]});
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
            }
        }
        return ans;
    }