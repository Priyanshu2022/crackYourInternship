// start and end
// break at every point
// and calculate left nodes and right nodes , attach
vector<TreeNode*> solve(int start,int end){
        vector<TreeNode*> ans;
        if(start==end){
            ans.push_back(new TreeNode(start));
            return ans;
        }
        else if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        else if(start<end){
            for(int k=start;k<=end;k++){
                vector<TreeNode*> left=solve(start,k-1); // will generate all left trees
                vector<TreeNode*> right=solve(k+1,end);  //                   right
                for(int i=0;i<left.size();i++){
                    for(int j=0;j<right.size();j++){
                        TreeNode* root=new TreeNode(k);
                        root->left=left[i];
                        root->right=right[j];
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }