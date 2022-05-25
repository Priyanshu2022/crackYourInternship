// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// push the starting word in queue
// now iterate on this , try to change with every char
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> mp;
        for(int i=0;i<wordList.size();i++) mp[wordList[i]]++;
        queue<string> q;
        q.push(beginWord);
        if(mp.find(endWord)==mp.end()) return 0;
        int ans=0;
        while(!q.empty()){
            ans++;
            int size=q.size();
            while(size--){
                string cur=q.front();
                q.pop();
                for(int i=0;i<cur.length();i++){
                    string temp=cur;
                    for(int j=0;j<26;j++){
                        temp[i]=j+'a';
                        if(mp.find(temp)==mp.end()) continue;
                        if(temp==endWord) return ans+1;
                        q.push(temp);
                        mp.erase(temp);
                    }
                }
            }
        }
        return 0;
    }