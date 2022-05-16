//Given two strings s and t, return true if they are equal 
//when both are typed into empty text editors. 
//'#' means a backspace character.
bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!st1.empty())
                st1.pop();
            }
            else st1.push(s[i]);
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!st2.empty())
                st2.pop();
            }
            else st2.push(t[i]);
        }
        if(st1.size()!=st2.size()) return false;
        else{
            while(st1.size() && st2.size()){
                if(st1.top()==st2.top()){
                    st1.pop();
                    st2.pop();
                }
                else return false;
            }
        }
        return true;
    }