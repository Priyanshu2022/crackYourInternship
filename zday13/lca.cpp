// if root is one of p and q return root
// call for left and right
// if getting answer from both the sides return root
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        else if(left!=NULL && right==NULL) return left;
        else if(left==NULL && right!=NULL) return right;
        else return NULL;
    }