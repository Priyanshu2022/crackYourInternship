string solve(TreeNode* root,unordered_map<string,vector<TreeNode*>> &mp){
        if(root==NULL) return "";
        string s="";
        s+='(';
        s+=solve(root->left,mp);
        s+=to_string(root->val);
        s+=solve(root->right,mp);
        s+=')';
        mp[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> mp;
        solve(root,mp);
        vector<TreeNode*> ans;
        for(auto it:mp){
            if(it.second.size()>=2){
                ans.push_back(it.second[0]);
            }
        }
        return ans;
    }