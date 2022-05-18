// lca of bst
// if root ==null return null
// if both nodes on right go to the right , if both nodes at left , move left
// else return root
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else return root;
    }