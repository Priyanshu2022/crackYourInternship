// bst from preorder
// maintain a bound and iterate in the preorder and make nodes
TreeNode* build(vector<int> &preorder,int &i,int bound){
        if(i==preorder.size() || preorder[i]>bound) return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }