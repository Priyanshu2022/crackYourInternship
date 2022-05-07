// hashing
// sort NlogN
// slow fast
// slow and fast will meet and put fast at start now when both will meet is duplicate
int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
}

// if i and j are not equal swap i+1 and j
int removeDuplicates(vector<int>& a) {
        if(a.size()==0) return 0;
        int i=0;
        for(int j=0;j<a.size();j++){
            if(a[i]!=a[j]){
                i++;
                a[i]=a[j];
            }
        }
        return i+1;
    }

// if nums[i] not equal to zero then swap with j and and j++
void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) {
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }

// two sum
// hashing or nlong

// take 3 pointers low , mid and high . where 0 to low-1 will be zero and high +1 end will be 2
void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }

// set matrix zero
// Assuming all the elements in the matrix are non-negative. Traverse through the matrix and if you find an element with value 0
// , then change all the elements in its row and column to -1, except when an element is 0. The reason for not changing other 
// elements to 0, but -1, is because that might affect other columns and rows. Now traverse through the matrix again and if an 
// element is -1 change it to 0, which will be the answer.

// minimum till now 
int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]>=mini) ans=max(ans,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return ans;
    }

// when we get a minima find next maxima and add difference to profit
int maxProfit(vector<int>& a) {
        int profit=0;
        for(int i=1;i<a.size();i++){
            if(a[i]>a[i-1]) profit+=(a[i]-a[i-1]);
        }
        return profit;
    }

// if y1=mx+k and y2=nx+k then there difference which is (m-n)x is divisible by k
// addding k in sum%k+k to handle negative remainders
// mp[0]=1 indicates starting with one zero remainder subarray
int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp[(sum%k+k)%k]){
                ans+=mp[(sum%k+k)%k];
            }
            mp[(sum%k+k)%k]++;
        }
        return ans;   
    }


// numbers are from 1 to n go to nums[nums[i]-1] and make it negative if it is not , and if it is negative push nums[i]
// in vector as it make us go to the same index again 
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            if(nums[n-1]<0) ans.push_back(n);
            else nums[n-1]*=-1;
        }
        return ans;
    }

// i at  0 and j at n-1 , calculate area and move pointer where height is less
int maxArea(vector<int>& height) {
        int ans=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            ans=max(ans,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]){
                i++;
            }
            else j--;
        }
        return ans;
    }

// maximum score from cards
// calculate sum of first k , then check all possible cases by
// subtracting last from first k and adding last element from n
int maxScore(vector<int>& cardPoints, int k) {
        int temp=0,sum;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            temp+=cardPoints[i];
        }
        sum=temp;
        for(int i=0;i<k;i++){
            temp=temp-cardPoints[k-i-1]+cardPoints[n-i-1];
            sum=max(sum,temp);
        }
        return sum;
    }

// starting with one zero sum subarray 
int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowStart=0,rowEnd=matrix.size()-1,colStart=0,colEnd=matrix[0].size()-1;
        int total=matrix.size()*matrix[0].size();
        int count=0;
        while(count<total){
            for(int index=colStart;count<total&&index<=colEnd;index++){
                ans.push_back(matrix[rowStart][index]);
                count++;
            }
            rowStart++;
            for(int index=rowStart;count<total&&index<=rowEnd;index++){
                ans.push_back(matrix[index][colEnd]);
                count++;
            }
            colEnd--;
            for(int index=colEnd;count<total&&index>=colStart;index--){
                ans.push_back(matrix[rowEnd][index]);
                count++;
            }
            rowEnd--;
            for(int index=rowEnd;count<total&&index>=rowStart;index--){
                ans.push_back(matrix[index][colStart]);
                count++;
            }
            colStart++;
        }
        
        return ans;
    }

// last kaha se jump karsakte hai
bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=last) last=i;
        }
        return last==0;
    }


// bfs
bool bfs(vector<vector<char>>& board,int i,int j,string word,int index,vector<vector<int>> &vis){
        if(index==word.length()) return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0) return false;
        if(board[i][j]!=word[index]) return false;
        if(vis[i][j]) return false;
        else vis[i][j]=1;
        if(bfs(board,i+1,j,word,index+1,vis) || bfs(board,i-1,j,word,index+1,vis) || bfs(board,i,j+1,word,index+1,vis) || bfs(board,i,j-1,word,index+1,vis)) return true;
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(bfs(board,i,j,word,0,vis)) return true;
            }
        }
        return false;
    }

