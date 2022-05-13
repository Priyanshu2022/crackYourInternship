// smallest letter greater than target
// Note that the letters wrap around.
char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0;
        int h=letters.size()-1;
        int ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(letters[m]>target){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        if(ans==-1) return letters[0];
        else return letters[ans];
    }