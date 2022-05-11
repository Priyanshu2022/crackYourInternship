    // digit
    // e / E => must come up once , digit must be present before,cannot be at last
    // dot => once,e cannot come before this,last and no digit before
    // +/- => can come at start and after e
    bool isNumber(string s) {
        bool digit=false,e=false,dot=false;
        int countPlusMinus=0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                digit=true;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(digit==false || e==true || i==s.length()-1 ) return false;
                e=true;
            }
            else if(s[i]=='.'){
                if(dot || e==true || (i==s.length()-1 && digit==false) ) return false;
                dot=true;
            }
            else if(s[i]=='+' || s[i]=='-'){
                if(countPlusMinus==2) return false;
                if((i>0 && (s[i-1]!='e' && s[i-1]!='E')) || i==s.length()-1) return false;
                countPlusMinus++;
            }
            else return false;
        }
        return true;
    }