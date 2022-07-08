// jump game 2
// there variables -> jumps, cur, farthest
int jump(vector<int>& nums) {
        int n=nums.size();
        
        int jumps=0;
        int cur=0;
        int farthest=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(i==cur){
                jumps++;
                cur=farthest;
            }
        }
        return jumps;
    }