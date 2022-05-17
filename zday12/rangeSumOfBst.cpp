// find the sum of nodes in range low and high
// the given tree is bst
// so we can further optimise it
// if low > root->val then in range nodes can only be in right part
// if high < root->val then in range nodes can only be in left part
int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high)+
        ((root->val>=low && root->val<=high)?root->val:0);
    }