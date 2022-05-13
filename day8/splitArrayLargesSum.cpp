// Given an array nums which consists of non-negative integers and an integer m, 
// you can split the array into m non-empty continuous subarrays.
// Write an algorithm to minimize the largest sum among these m subarrays
// l=maximum element
// h=sum of subarray
// mid=maximum sum of a subarray
int possibleSubarray(int mid,vector<int> &nums){
        int subcount=1;
        int curSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+curSum<=mid){
                curSum+=nums[i];
            }
            else{
                subcount++;
                curSum=nums[i];
            }
        }
        return subcount;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        int l=*max_element(nums.begin(),nums.end());
        int h=sum;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possibleSubarray(mid,nums)<=m){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }