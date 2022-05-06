// if y1=mx+k and y2=nx+k then there difference which is (m-n)x is divisible by k
// addding k in sum%k+k to handle negative remainders
// mp[0]=1 indicates starting with one zero remainder subarray
int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp[(sum%k+k)%k]){
                ans+=mp[(sum%k+k)%k];
            }
            mp[(sum%k+k)%k]++;
        }
        return ans;   
    }