// decode string
// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// if digit calculate num
// if alpha add in res
// if opening push both and update to zero
// if closing , add res nums.top()-1 times and add chars .top from start
// then pop both
string decodeString(string s) {
        stack<int> nums;
        stack<string> chars;
        string res="";
        int num=0;
        for(auto c:s){
            if(isdigit(c)) num=num*10+c-'0';
            else if(isalpha(c)) res+=c;
            else if(c=='['){
                nums.push(num);
                chars.push(res);
                num=0;
                res="";
            }
            else if(c==']'){
                string temp=res;
                for(int i=0;i<nums.top()-1;i++){
                    res+=temp;
                }
                res=chars.top()+res;
                nums.pop();
                chars.pop();
            }
        }
        return res;
    }