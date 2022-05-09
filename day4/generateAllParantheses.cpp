// generate all parantheses
// have a count of open and close bracket
void generate(vector<string> &ans,string &s,int n,int open,int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s+='(';
            generate(ans,s,n,open-1,close);
            s.pop_back();
        }
        if(close>0 && close>open){
            s+=')';
            generate(ans,s,n,open,close-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        generate(ans,s,n,n,n);
        return ans;
    }