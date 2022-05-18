// maintain a path and count
void solve(TreeNode* root,int k,vector<int> &path,int &count){
        if(root==NULL) return ;
        path.push_back(root->val);
        solve(root->left,k,path,count);
        solve(root->right,k,path,count);
        long long int sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==k) count++;
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count=0;
        solve(root,targetSum,path,count);
        return count;
    }