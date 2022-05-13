// every element in the array except one appers twice find that element
int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<h){
            int m=(l+h)/2;
            if((m%2==0 && nums[m]==nums[m+1]) || (m%2!=0 && nums[m]==nums[m-1])){
                l=m+1;
            }
            else{
                h=m;
            }
        }
        return nums[h];
    }