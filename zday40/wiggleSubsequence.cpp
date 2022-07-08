// wiggle subsequnce
int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int prev=nums[1]-nums[0];
        int ans=2;
        if(prev==0) ans=1;
        for(int i=2;i<n;i++){
            if((prev>=0 && (nums[i]-nums[i-1])<0)||(prev<=0 && (nums[i]-nums[i-1]>0))){
                prev=nums[i]-nums[i-1];
                ans++;
            }
        }
        return ans;
    }