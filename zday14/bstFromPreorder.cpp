// no need of lower bound
// maintain a upper bound
// if going to the left current nodes's value becomes the upper bound
// else if going to the right upperBound of currentnode become's the upperbound
TreeNode* build(vector<int> &preorder,int &i,int bound){
        if(i==preorder.size() || preorder[i]>bound) return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;// for preorder traversal(first node is root)
        return build(preorder,i,INT_MAX);
    }