vector<int> diffWaysToCompute(string s) {
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*' || s[i]=='+' || s[i]=='-'){
                vector<int> left=diffWaysToCompute(s.substr(0,i));
                vector<int> right=diffWaysToCompute(s.substr(i+1));
                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){
                        if(s[i]=='+') ans.push_back(left[j]+right[k]);
                        else if(s[i]=='*') ans.push_back(left[j]*right[k]);
                        else ans.push_back(left[j]-right[k]);
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(stoi(s));
        return ans;
    }