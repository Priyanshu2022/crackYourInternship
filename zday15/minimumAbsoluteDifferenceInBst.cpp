// maintain a prev and do inorder
void solve(TreeNode* root,int &mini,TreeNode* &prev){
        if(root==NULL) return;
        solve(root->left,mini,prev);
        if(prev==NULL){
            prev=root;
        }
        else{
            mini=min(mini,root->val-prev->val);
            prev=root;
        }
        solve(root->right,mini,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        TreeNode* prev=NULL;
        solve(root,mini,prev);
        return mini;
    }