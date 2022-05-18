// first create parent mapping
// then maintain a visited map
// and make a queue
void createParentMapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_map<TreeNode*,bool> vis;
        createParentMapping(root,mp);
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int curDistance=0;
        while(!q.empty()){
            if(curDistance==k) break;
            curDistance++;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left]){
                    vis[temp->left]=1;
                    q.push(temp->left);
                }
                if(temp->right && !vis[temp->right]){
                    vis[temp->right]=1;
                    q.push(temp->right);
                }
                if(mp[temp] && !vis[mp[temp]]){
                    vis[mp[temp]]=1;
                    q.push(mp[temp]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }