// '.' as current directory
// '..' as parent directory
// '/' ignore firstly
// else everything is directory name
// put names in stack , if '..' comes pop the top one
// then make ans by popping
string simplifyPath(string path) {
        stack<string> st;
        for(int i=0;i<path.length();i++){
            if(path[i]=='/') continue;
            string temp="";
            int j=i;
            while(j<path.length() && path[j]!='/'){
                temp+=path[j];
                j++;
            }
            if(temp.length()==2 && temp[0]=='.' && temp[1]=='.'){
                    if(!st.empty()) st.pop();
            }
            else if(temp.length()==1 && temp[0]=='.') continue;
            else st.push(temp);
            i=j;
        }
        string ans="";
        if(st.empty()){
            ans+='/';
        }
        else{
            while(!st.empty()){
                ans='/'+st.top()+ans;
                st.pop();
            }
        }
        return ans;
        
    }