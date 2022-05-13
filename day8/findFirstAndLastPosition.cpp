// first and last position in array
vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        low=0;
        high=nums.size()-1;
        int ans2=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans2=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        vector<int> v;
        v.push_back(ans);
        v.push_back(ans2);
        return v;
    }