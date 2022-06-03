// if only one of the child is null then , that node is not leaf
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        return (left==0||right==0)?left+right+1:min(left,right)+1;
    }