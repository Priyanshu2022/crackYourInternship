string ones[20] = {"","One ","Two ","Three ","Four ",
   "Five ","Six ","Seven " ,"Eight ",
        "Nine ","Ten ","Eleven ","Twelve "
        ,"Thirteen ","Fourteen ","Fifteen "
        ,"Sixteen ","Seventeen ",
        "Eighteen ","Nineteen ",};

        string tens[10] = {"","","Twenty "
        ,"Thirty ","Forty ","Fifty "
        ,"Sixty ","Seventy ","Eighty ",
        "Ninety "};
    
    string num2word(int n,string s,bool flag)
    {
        string ans = ""; 
        
         if(n>19 && n<100)
            ans+=tens[n/10]+ones[n%10];
        
        else if(n>=100)
        {
            ans+=ones[n/100]+"Hundred ";
            n=n%100;
            if(n>19)
            {
                ans+=tens[n/10]+ones[n%10];
            }
            else ans+=ones[n];
        }
        else
        {
            ans+=ones[n];
        }
        if(flag && ans.size()) ans+=s;
        
        return ans;
    }
    
    string numberToWords(int num) 
    {
        bool flag;
        string ans="";
        if(!num) return "Zero";
        ans+=num2word(num/1000000000 ,"Billion ",num/1000000000);
        ans+=num2word((num/1000000)%1000,"Million ",num/1000000);
        ans+=num2word((num/1000)%1000,"Thousand ",num/1000);
        ans+=num2word((num/100)%10,"Hundred ",num/100);
        ans+=num2word((num%100),"",false);
        
        ans.pop_back();
        return ans;
        
    }