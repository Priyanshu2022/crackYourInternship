// sum root to leaf numbers
void solve(TreeNode* root,int curSum,int &sum){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            sum+=curSum*10+root->val;
            return ;
        }
        solve(root->left,curSum*10+root->val,sum);
        solve(root->right,curSum*10+root->val,sum);
    }
    int sumNumbers(TreeNode* root) {
        int curSum=0;
        int sum=0;
        solve(root,curSum,sum);
        return sum;
    }