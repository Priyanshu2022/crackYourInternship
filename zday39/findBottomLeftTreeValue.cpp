void solve(TreeNode* root,int level,int &maxLevel,int &ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            if(level>maxLevel){
                ans=root->val;
                maxLevel=level;
                return ;
            }
        }
        solve(root->left,level+1,maxLevel,ans);
        solve(root->right,level+1,maxLevel,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int level=0;
        int maxLevel=-1;
        int ans=-1;
        solve(root,level,maxLevel,ans);
        return ans;
    }