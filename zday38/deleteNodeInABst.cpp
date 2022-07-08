// delete a node in bst
// find the node , delete it by connecting largest of left tree with right
TreeNode* rightMostFromLeft(TreeNode* root){
        if(root->right==NULL) return root;
        return rightMostFromLeft(root->right);
    }
    TreeNode* solve(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* rightChild=root->right;
        TreeNode* rightMost=rightMostFromLeft(root->left);
        rightMost->right=rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return solve(root);
        TreeNode* cur=root;
        while(cur){
            if(cur->val>key){
                if(cur->left && cur->left->val==key){
                    cur->left=solve(cur->left);
                    break;
                }
                else{
                    cur=cur->left;
                }
            }
            else{
                if(cur->right && cur->right->val==key){
                    cur->right=solve(cur->right);
                    break;
                }
                else{
                    cur=cur->right;
                }
            }
        }
        return root;
    }