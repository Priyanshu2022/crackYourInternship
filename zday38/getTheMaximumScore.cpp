int mod=1000000007;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        ll ans=0,sum1=0,sum2=0;
        int i=0,j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) sum1+=nums1[i++];
            else if(nums1[i]>nums2[j]) sum2+=nums2[j++];
            else{
                ans+=max(sum1,sum2)%mod+nums1[i];
                i++;
                j++;
                sum1=sum2=0;
            }
        }
        while(i<n) sum1+=nums1[i++];
        while(j<m) sum2+=nums2[j++];
        ans+=max(sum1,sum2);
        return ans%mod;
    }