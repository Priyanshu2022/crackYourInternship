// check if subRoot is a subtree of root
// time complexity=O(n*m) , space =O(min(m,n))
// for every node of root we will traverse subRoot , and match them 
bool isSameTree(TreeNode* root,TreeNode* subRoot){
        // if one of them is null , return true is both of them are null else false
        if(root==NULL || subRoot==NULL) return (root==NULL&&subRoot==NULL);
        if(root->val!=subRoot->val) return false;
        else return (isSameTree(root->left,subRoot->left)&&isSameTree(root->right,subRoot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(isSameTree(root,subRoot)) return true;
        else return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }