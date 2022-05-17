// all path from root to leaf
void solve(TreeNode* root,vector<string> &ans,string s){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return ;
        }
        if(root->left) solve(root->left,ans,s+"->"+to_string(root->left->val));
        if(root->right) solve(root->right,ans,s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s=to_string(root->val);
        solve(root,ans,s);
        return ans;
    }