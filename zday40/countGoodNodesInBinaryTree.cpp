// count good nodes in binary tree
void solve(TreeNode* root,int maxi,int &ans){
        if(root==NULL) return ;
        solve(root->left,max(maxi,root->val),ans);
        if(root->val>=maxi) ans++;
        solve(root->right,max(maxi,root->val),ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        solve(root,INT_MIN,ans);
        return ans;
    }