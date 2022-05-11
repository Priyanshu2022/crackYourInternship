vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> ans;
        while(i<words.size()){
            int wc=words[i].length();
            int j=i+1;
            int spaces=0;
            while(j<words.size() && wc+words[j].length()+1+spaces<=maxWidth){
                wc+=words[j].length();
                spaces++;
                j++;
            }
            int vac=maxWidth-wc;
            int atleast= spaces==0 ?0:vac/spaces;
            int extra= spaces==0 ? 0:vac%spaces;
            string temp="";
            if(j>=words.size()){ // last line
                for(int k=i;k<j;k++){
                    temp+=words[k];
                    if(vac){
                        temp+=" ";
                        vac--;
                    }
                }
                while(vac) temp+=" ",vac--;
            }
            else if(j-i==1){ // only one string 
                temp+=words[i];
                for(int m=0;m<vac;m++) temp+=" ";
            }
            else{
                for(int k=i;k<j;k++){
                    temp+=words[k];
                    if(k==j-1) continue;
                    for(int m=0;m<atleast;m++) temp+=" ";
                    if(extra){
                        temp+=" ";
                        extra--;
                    }
                }
            }
            ans.push_back(temp);
            i=j;
        }
        return ans;
    }