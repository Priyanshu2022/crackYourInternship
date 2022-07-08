struct Node{
        Node* links[26];
        bool flag=false;
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        void put(char ch,Node* node){
            links[ch-'a']=node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag=true;
        }
        bool isEnd(){
            return flag;
        }
    };
class Solution {
public:
    Node* root=new Node();
    void insert(string word){
        Node* node =root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                node->put(word[i],new Node());
                node=node->get(word[i]);
            }
        }
        node->setEnd();
    }
    vector<string> search(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return {};
            }
            node=node->get(prefix[i]);
        }
        vector<string> res;
        dfs(node,prefix,res);
        return res;
    }
    void dfs(Node* node,string pre,vector<string> &res){
        if(res.size()==3) return ;
        if(node->isEnd()) res.push_back(pre);
        for(int i=0;i<26;i++){
            if(node->containsKey((char)(i+'a'))){
                dfs(node->get((char)(i+'a')),pre+(char)(i+'a'),res);
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(int i=0;i<products.size();i++){
            insert(products[i]);
        }
        vector<vector<string>> ans;
        string prefix="";
        for(int i=0;i<searchWord.size();i++){
            prefix+=searchWord[i];
            ans.push_back(search(prefix));
        }
        return ans;
    }
};