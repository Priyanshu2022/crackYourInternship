// alien dictionary
// given sorted words 
// we have to return the order of alphabets in their language
// for every consecutive words , because of the first unmatching char first word comes before then second
// link those words in graph
// now find topo sort
void dfs(int node,vector<vector<int>> &g,vector<int> &vis,string &ans){
        vis[node]=1;
        for(auto it:g[node]){
            if(!vis[it]) dfs(it,g,vis,ans);
        }
        ans=ans+(char)(node+'a');
    }
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> g(K);
        for(int i=0;i<N-1;i++){
            string word1=dict[i];
            string word2=dict[i+1];
            for(int j=0;j<word1.length()&&j<word2.length();j++){
                if(word1[j]!=word2[j]){
                    g[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        vector<int> vis(K,0);
        string ans="";
        for(int i=0;i<K;i++){
            if(!vis[i]){
                dfs(i,g,vis,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }