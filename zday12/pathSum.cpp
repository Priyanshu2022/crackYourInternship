// root to leaf with given target sum
bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->val==targetSum && root->left==NULL && root->right==NULL) return true;
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }