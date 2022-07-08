// most frequent subtree sum
int solve(TreeNode* root,unordered_map<int,int> &mp,int &maxi){
        if(root==NULL) return 0;
        int sum=root->val;
        sum+=solve(root->left,mp,maxi);
        sum+=solve(root->right,mp,maxi);
        mp[sum]++;
        maxi=max(maxi,mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        solve(root,mp,maxi);
        vector<int> ans;
        for(auto it:mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }