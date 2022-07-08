string ones[20]={"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
    string tens[10]={"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
    
    string numToWord(int n,string s){
        string ans="";
        if(n>19){
            ans+=tens[n/10]+ones[n%10];
        }
        else{
            ans+=ones[n];
        }
        if(n) ans+=s;
        return ans;
    }
    string convertToWords(long n) {
        string res="";
        res+=numToWord(n/10000000,"crore ");
        res+=numToWord((n/100000)%100,"lakh ");
        res+=numToWord((n/1000)%100,"thousand ");
        res+=numToWord(((n/100)%10),"hundred ");
        if(n>100 && n%100){
            res+="and ";
        }
        res+=numToWord(n%100,"");
        res.pop_back();
        return res;
    }