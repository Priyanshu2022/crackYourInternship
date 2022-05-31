int trap(vector<int>& a) {
        int l=0;
        int r=a.size()-1;
        int ans=0;
        int leftMax=0;
        int rightMax=0;
        while(l<=r){
            if(a[l]<=a[r]){
                if(a[l]<=leftMax) ans+=leftMax-a[l];
                else leftMax=a[l];
                l++;
            }
            else{
                if(a[r]<=rightMax) ans+=rightMax-a[r];
                else rightMax=a[r];
                r--;
            }
        }
        return ans;
    }