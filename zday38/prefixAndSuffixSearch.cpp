// prefix and suffix search
// make a map of string ,int
// for every prefix and suffix pair store the index of word 
unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string word=words[i];
            for(int j=1;j<=word.size();j++){
                string p=word.substr(0,j);
                for(int k=0;k<word.size();k++){
                    string s=word.substr(k);
                    mp[p+"-"+s]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(mp.find(prefix+'-'+suffix)==mp.end()) return -1;
        else return mp[prefix+'-'+suffix];
    }