// group anagrams(words with rearranged alphabets)
// map<string,vector<string>>
// sort and put in map
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto &cur:strs){
            string temp=cur;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(cur);
        }
        for(auto &cur:mp){
            ans.push_back(cur.second);
        }
        return ans;
    }