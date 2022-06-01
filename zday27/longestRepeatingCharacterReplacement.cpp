// left and right will be at zero, if valid move right , if not move left till it is valid
    // valid means we can make the substring equal
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int maxCount=0;
        int ans=0;
        unordered_map<char,int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            maxCount=max(maxCount,mp[s[j]]);
            while(((j-i+1)-maxCount)>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }