// two approches one with n space other with constant
    // maintaine two arrays 
    // one of considering that only left part ratings i.e. if left's rating is less , add one to current ,else reset to one
    // similarly for right part , sum of max of every position will be answer
    
    // Optimal
    // at every peak calculate answer 
    int candy(vector<int>& a) {
        int ans=0;
        int n=a.size();
        int i=0;
        while(i<n){
            int lc=1,rc=1;
            while((i+1)<n && a[i+1]>a[i]) i++,lc++;
            while((i+1)<n && a[i+1]<a[i]) i++,rc++;
            if(lc>rc) ans+=lc*(lc+1)/2+(rc-1)*(rc)/2;
            else ans+=rc*(rc+1)/2 + (lc-1)*(lc)/2;
            if(i+1<n && a[i+1]>a[i]) ans--,i--;
            i++;
        }
        return ans;
    }