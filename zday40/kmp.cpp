// kmp
vector <int> search(string p, string s)
        {
            int m=p.size();
            int n=s.size();
            vector<int> lps(m);
            lps[0]=0;
            int len=0;
            int i=1;
            while(i<m){
                if(p[i]==p[len]){
                    lps[i++]=++len;
                }else{
                    if(len==0) lps[i++]=0;
                    else len=lps[len-1];
                }
            }
            i=0;
            int j=0;
            vector<int> ans;
            while(i<n){
                if(p[j]==s[i]){
                    i++;
                    j++;
                }
                if(j==m){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }else if(i<n && p[j]!=s[i]){
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else i++;
                }
            }
            return ans;
        }