// for all divisors
bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                string temp=s.substr(0,i);
                string tempString="";
                for(int j=0;j<(n/i);j++){
                    tempString+=temp;
                }
                if(tempString==s) return true;
            }
        }
        return false;
    }