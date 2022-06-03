// permuations have duplicates
// generate all possible unique permutaion 
void solve(int index,vector<int> &nums,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return ;
        }
        set<int> st;
        for(int i=index;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i],nums[index]);
            solve(index+1,nums,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }