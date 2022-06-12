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



// calculate next smaller elements and prev smaller element
// then calulate area
// if next[i]==-1 next[i]=n (max)
// prev[i]==-1 then breadth is already (min)
// breadth=next[i]-prev[i]+1
vector<int> nextSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next;
        next=nextSmaller(heights,n);
        vector<int> prev;
        prev=prevSmaller(heights,n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(next[i]==-1) next[i]=n;
            ans=max(ans,heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }


int majorityElement(vector<int>& a) {
        int count=0;
        int element=-1;
        for(int i=0;i<a.size();i++){
            if(count==0) element=a[i];
            if(element==a[i]) count++;
            else count--;
        }
        return element;
    }

// x is given in sorted order , and i<j 
    // therefore x[i]<x[j]
    // the equation becomes yi+yj+xj-xi=xj+yj+(yi-xi)
    // we can store yi-xj which is changing in priority queue
    // for current point we will check the maximum value of yi-xi
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++){
            while((!pq.empty())&&abs(pq.top().second-points[i][0])>k) pq.pop();
            if(!pq.empty()){
                ans=max(ans,points[i][0]+points[i][1]+pq.top().first);
            }
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }

// merge two sorted arrays
// GAP method
//Initially take the gap as (m+n)/2;
// Take as a pointer1 = 0 and pointer2 = gap.
// Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
// After completion of the loop reduce the gap as gap=gap/2.
// Repeat the process until gap>0.


int merge(vector<int>& nums,int start,int end,int mid){
        int count=0;
        int l=start,h=mid+1;
        while(l<=mid && h<=end){
            if((long long int)nums[l]>(long long int)2*nums[h]){
                count+=(mid-l+1);
                h++;
            }
            else l++;
        }
        int temp[end-start+1];
        int t=0;
        l=start,h=mid+1;
        while(l<=mid && h<=end){
            if(nums[l]>nums[h]){
                temp[t++]=nums[h++];
            }
            else temp[t++]=nums[l++];
        }
        while(l<=mid) temp[t++]=nums[l++];
        while(h<=end) temp[t++]=nums[h++];
        for(int i=0;i<end-start+1;i++){
            nums[start+i]=temp[i];
        }
        return count;
    }
    int mergeSort(vector<int>& nums,int start,int end){
        if(start>=end) return 0;
        int mid=(start+end)/2;
        int count=mergeSort(nums,start,mid);
        count+=mergeSort(nums,mid+1,end);
        count+=merge(nums,start,end,mid);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }

// for(i to n){
// {for(j to m){
// if([j]!=[i]) bool false and break;
int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            bool f=1;
            for(int j=0;j<needle.size();j++){
                if(needle[j]!=haystack[i+j]){
                    f=0;
                    break;
                }
            }
            if(f) return i;
        }
        return -1;
    }


// if it is an open bracket push it
// else check if top has corresponding open 
bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(st.empty()){
                return false;
            }
            if(s[i]==')')
            {
                if(st.top()!='(') return false;
                else st.pop();
            }
            if(s[i]=='}')
            {
                if(st.top()!='{') return false;
                else st.pop();
            }
            if(s[i]==']')
            {
                if(st.top()!='[') return false;
                else st.pop();
            }
        }
        return st.empty();

        
        
    }


// take first string and
// loop through it and match its element by iterating in rest all strings
string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            bool f=1;
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size() || strs[0][i]!=strs[j][i]){
                    f=0;
                    break;
                }
            }
            if(f) ans+=strs[0][i];
            else break;
        }
        return ans;
    }

// valid palindrome after deleting atmost one character
bool helper(string &s,int l,int h,int count){
        if(count>1) return false;
        while(l<=h){
            if(s[l]==s[h]){
                l++;
                h--;
            }
            else{
                return helper(s,l+1,h,count+1) || helper(s,l,h-1,count+1);
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return helper(s,0,s.length()-1,0);
    }

// generate all parantheses
// have a count of open and close bracket
void generate(vector<string> &ans,string &s,int n,int open,int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s+='(';
            generate(ans,s,n,open-1,close);
            s.pop_back();
        }
        if(close>0 && close>open){
            s+=')';
            generate(ans,s,n,open,close-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        generate(ans,s,n,n,n);
        return ans;
    }

// store all numbers according to roman in a vector
// iterate through the vector in descending order and
// check if it is greater than num or not 
// if num is greater subtract and add it to the string
string intToRoman(int num) {
        vector<pair<int,string>> v;
        v.push_back({1000,"M"});
        v.push_back({900,"CM"});
        v.push_back({500,"D"});
        v.push_back({400,"CD"});
        v.push_back({100,"C"});
        v.push_back({90,"XC"});
        v.push_back({50,"L"});
        v.push_back({40,"XL"});
        v.push_back({10,"X"});
        v.push_back({9,"IX"});
        v.push_back({5,"V"});
        v.push_back({4,"IV"});
        v.push_back({1,"I"});
        string ans="";
        
        for(int i=0;i<v.size();i++){
            while(num>=v[i].first){
                num-=v[i].first;
                ans+=v[i].second;
            }
        }
        return ans;
    }


// group anagrams(words with rearranged alphabets)
// map<string,vector<string>>
// sort and put in map
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto &cur:strs){
            string temp=cur;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(cur);
        }
        for(auto &cur:mp){
            ans.push_back(cur.second);
        }
        return ans;
    }


 // string can be " hello world   "
 // skip spaces 
 // make a ans(result) variable
 // sub = substring from i to j
 // if nothing in result store sub
 // else result=sub+" "+result
 string reverseWords(string s) {
        string result;
        int i = 0;
        int n = s.length();

        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            int j = i + 1;
            while(j < n && s[j] != ' ') j++;
            string sub = s.substr(i, j-i);
            if(result.length() == 0) result = sub;
            else result = sub + " " + result;
            i = j+1;
        }
        return result;
    }



// we have to tell minimum substring where all characters of second string present
// we will first store the char of 2nd string in map with their frequency
// matchedCount variable shows how many matched char are present in current substring (window)
// low is starting point of substring we are checking and high ending point
// if same length substring present then we have to return the one with minimum index (therefore we have minStart)
// idea is we will move till we will move high untill we will get a substring with all char of 2nd string
// then we will start decreasing the char by moving low , and whenever we find out we have removed the important char
// we will start increasing high again and start acquiring again
string minWindow(string s, string t) {
        unordered_map<char,int> letters;
        for(int i=0;i<t.length();i++) letters[t[i]]++;
        int matchedCount=0;
        int low=0;
        int minLength=INT_MAX;
        int minStart=0;
        for(int high=0;high<s.length();high++){
            if(letters[s[high]]>0) matchedCount++;// if we get the char we want , we will increase matchedCount
            letters[s[high]]--;//we have acquired that element 
            if(matchedCount==t.length()){// if we got all element 
                while(low<high && letters[s[low]]<0) letters[s[low]]++,low++;// we will start removing from start
                if(minLength>high-low+1){ // if minLength is greater than we will update it with misStart
                    minLength=high-low+1;
                    minStart=low;
                }
                letters[s[low]]++;// we will increase it's count , means we are leaving this one , we need this again
                low++;
                matchedCount--;
            }
        }
        return minLength==INT_MAX?"":s.substr(minStart,minLength);
    }



// there are two choice if we have remaining spaces greater than current word lenght
// then we can put it there or in next line
// index here is current word's index
int dp[501][2001];
    int solve(int index,int rem,vector<int> &arr,int &k){
        if(index==arr.size()) return 0;
        if(dp[index][rem]!=-1) return dp[index][rem];
        int ans;
        if(arr[index]>rem){
            ans=(rem+1)*(rem+1)+solve(index+1,k-arr[index]-1,arr,k);
        }
        else{
            ans=min((rem+1)*(rem+1)+solve(index+1,k-arr[index]-1,arr,k),solve(index+1,rem-arr[index]-1,arr,k));
        }
        dp[index][rem]=ans;
        return ans;
    }
    int solveWordWrap(vector<int>arr, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return solve(0,k,arr,k);
    } 


// rabin Karp
// rolling hash
// AABAACAADAABAABA   AABA
// occurances of AABA in 1st string
// one of the naive hash function can be A->1 B->2
// AABA = 1+1+2+1=5
// we will check window of 4 and check if its hash is same then we will compare
// hashing function's can be improved

    // digit
    // e / E => must come up once , digit must be present before,cannot be at last
    // dot => once,e cannot come before this,last and no digit before
    // +/- => can come at start and after e
    bool isNumber(string s) {
        bool digit=false,e=false,dot=false;
        int countPlusMinus=0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                digit=true;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(digit==false || e==true || i==s.length()-1 ) return false;
                e=true;
            }
            else if(s[i]=='.'){
                if(dot || e==true || (i==s.length()-1 && digit==false) ) return false;
                dot=true;
            }
            else if(s[i]=='+' || s[i]=='-'){
                if(countPlusMinus==2) return false;
                if((i>0 && (s[i-1]!='e' && s[i-1]!='E')) || i==s.length()-1) return false;
                countPlusMinus++;
            }
            else return false;
        }
        return true;
    }


// rabbbit rabbit
// number of times 2nd string occur as a subsequence in 1st string
// i=n-1, j=m-1
// if s[i]==t[j] there are two options either we can consider a[j] as occurence or look for anotheer
// therefore i-1 j-1(included) + i-1 j(not included)
// else i-1 j(cannot include)
int solve(string &s ,string &t,int index1,int index2,vector<vector<int>> &dp){
        if(index2<0) return 1;
        if(index1<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1]==t[index2]){
            return dp[index1][index2]=(solve(s,t,index1-1,index2-1,dp)+solve(s,t,index1-1,index2,dp));
        }
        else return dp[index1][index2]=solve(s,t,index1-1,index2,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return solve(s,t,s.length()-1,t.length()-1,dp);
    }


vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> ans;
        while(i<words.size()){
            int wc=words[i].length();
            int j=i+1;
            int spaces=0;
            while(j<words.size() && wc+words[j].length()+1+spaces<=maxWidth){
                wc+=words[j].length();
                spaces++;
                j++;
            }
            int vac=maxWidth-wc;
            int atleast= spaces==0 ?0:vac/spaces;
            int extra= spaces==0 ? 0:vac%spaces;
            string temp="";
            if(j>=words.size()){ // last line
                for(int k=i;k<j;k++){
                    temp+=words[k];
                    if(vac){
                        temp+=" ";
                        vac--;
                    }
                }
                while(vac) temp+=" ",vac--;
            }
            else if(j-i==1){ // only one string 
                temp+=words[i];
                for(int m=0;m<vac;m++) temp+=" ";
            }
            else{
                for(int k=i;k<j;k++){
                    temp+=words[k];
                    if(k==j-1) continue;
                    for(int m=0;m<atleast;m++) temp+=" ";
                    if(extra){
                        temp+=" ";
                        extra--;
                    }
                }
            }
            ans.push_back(temp);
            i=j;
        }
        return ans;
    }


// integer to english word
// ***************************************
// ***************************************
string ones[20] = {"","One ","Two ","Three ","Four ",
   "Five ","Six ","Seven " ,"Eight ",
        "Nine ","Ten ","Eleven ","Twelve "
        ,"Thirteen ","Fourteen ","Fifteen "
        ,"Sixteen ","Seventeen ",
        "Eighteen ","Nineteen ",};

        string tens[10] = {"","","Twenty "
        ,"Thirty ","Forty ","Fifty "
        ,"Sixty ","Seventy ","Eighty ",
        "Ninety "};
    
    string num2word(int n,string s,bool flag)
    {
        string ans = ""; 
        
         if(n>19 && n<100)
            ans+=tens[n/10]+ones[n%10];
        
        else if(n>=100)
        {
            ans+=ones[n/100]+"Hundred ";
            n=n%100;
            if(n>19)
            {
                ans+=tens[n/10]+ones[n%10];
            }
            else ans+=ones[n];
        }
        else
        {
            ans+=ones[n];
        }
        if(flag && ans.size()) ans+=s;
        
        return ans;
    }
    
    string numberToWords(int num) 
    {
        bool flag;
        string ans="";
        if(!num) return "Zero";
        ans+=num2word(num/1000000000 ,"Billion ",num/1000000000);
        ans+=num2word((num/1000000)%1000,"Million ",num/1000000);
        ans+=num2word((num/1000)%1000,"Thousand ",num/1000);
        ans+=num2word((num/100)%10,"Hundred ",num/100);
        ans+=num2word((num%100),"",false);
        
        ans.pop_back();
        return ans;
        
    }


// Ceiling in a sorted array
// given sorted array and x
// find it's ceil(smallest element greater or equal to x)
// use binary search


// pair with given difference
bool findPair(int arr[], int size, int n){
    int i=0;
    int j=1;
    sort(arr,arr+size);
    while(i<size && j<size){
        if(arr[j]-arr[i]==n && i!=j) return true;
        else if(arr[j]-arr[i]>n) i++;
        else j++;
    }
    return false;
}


// maximal rectangle 
// given binary matrix
// find maximal rectangle of 1's
// 1 0 1 0 0 
// 1 0 1 1 1
// 1 1 1 1 1 
// 1 0 0 1 0
// move from row 1 to last (curRow) and calculate area if it was a histogram(it is like a histogram)
// add lower row one by one (if element is 0 curRow[j]=0 else curRow[j]++)
// return the maximum area
vector<int> nextSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int maxHistogram(vector<int>& heights) {
        int n=heights.size();
        vector<int> next;
        next=nextSmaller(heights,n);
        vector<int> prev;
        prev=prevSmaller(heights,n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(next[i]==-1) next[i]=n;
            ans=max(ans,heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') mat[i][j]=1;
            }
        }
        vector<int> curRow=mat[0];
        int maxAns=maxHistogram(curRow);
        for(int i=1;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    curRow[j]++;
                }
                else curRow[j]=0;
            }
            int curAns=maxHistogram(curRow);
            maxAns=max(curAns,maxAns);
        }
        return maxAns;
    }


  // number of islands
  // ["1","1","1","1","0"],
  // ["1","1","0","1","0"],
  // ["1","1","0","0","0"],
  // ["0","0","0","0","0"]
// check every element if it's one and not visited
// run dfs on it 
void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return; 
        if(grid[i][j]=='0') return;
        if(vis[i][j]!=-1) return ;
        vis[i][j]=1;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }



// Permute two arrays such that sum of every pair is greater or equal to K
// sort 1st array ascending and the other descending
// now check sum of ith elements


// find post order from inorder and pre order
// first elements of preorder will give root node's 
// then according to root node divide inorder in left and right half
int search(int arr[], int x, int n) 
{ 
    for (int i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 

void printPostOrder(int in[], int pre[], int n) 
{ 
    int root = search(in, pre[0], n); 
    if (root != 0) 
        printPostOrder(in, pre + 1, root); 
    if (root != n - 1) 
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1); 
    cout << pre[0] << " "; 
} 


// for every element product of array except self
// if prod!=0 simply prod/nums[i]
// else check if zeros are present how many times
// if zeros are greater than or equal to two every answer will be 0
// else excet that 0 every answer will be 0
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod=1;
        int zeros=0;
        for(int i=0;i<nums.size();i++) prod*=nums[i],nums[i]==0?zeros++:1;
        if(prod!=0){
            for(int i=0;i<nums.size();i++){
                ans.push_back(prod/nums[i]);
            }
        }
        else{
            if(zeros>=2){
                for(int i=0;i<nums.size();i++) ans.push_back(0);
            }
            else{
                prod=1;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]!=0) prod*=nums[i];
                }
                for(int i=0;i<nums.size();i++){
                    if(nums[i]!=0){
                        ans.push_back(0);
                    }
                    else ans.push_back(prod);
                }
            }
        }
        return ans;
    }


// Check if reversing a sub array make the array sorted
// 1st -> N*N
// 2nd -> NlogN 
// The idea is to compare the given array with the sorted array. Make a copy of the given array and sort it. Now, find // the first index and last index which do not match with sorted array. If no such indices are found, print “Yes”. 
// Else check if the elements between the indices are in decreasing order.
// 3rd -> 1st array should be increasing , then decreasing , then increasing


// rotate image
void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }


// '.' as current directory
// '..' as parent directory
// '/' ignore firstly
// else everything is directory name
// put names in stack , if '..' comes pop the top one
// then make ans by popping
string simplifyPath(string path) {
        stack<string> st;
        for(int i=0;i<path.length();i++){
            if(path[i]=='/') continue;
            string temp="";
            int j=i;
            while(j<path.length() && path[j]!='/'){
                temp+=path[j];
                j++;
            }
            if(temp.length()==2 && temp[0]=='.' && temp[1]=='.'){
                    if(!st.empty()) st.pop();
            }
            else if(temp.length()==1 && temp[0]=='.') continue;
            else st.push(temp);
            i=j;
        }
        string ans="";
        if(st.empty()){
            ans+='/';
        }
        else{
            while(!st.empty()){
                ans='/'+st.top()+ans;
                st.pop();
            }
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


// surrounded regions
// means regions of O's not connected to edge , we have to mark them x
// first we will change all O in corner(edges) and it's connected O's to * 
// then change the remaining O's to X 
// then we will again change the * to O
void change(vector<vector<char>> &board,int x,int y){
        board[x][y]='*';
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(cx>=0 && cx<board.size() && cy>=0 && cy<board[0].size()){
                if(board[cx][cy]=='O') change(board,cx,cy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // first we will change all O in corner and it's connected O's to * 
        // then change the remaining O's to X 
        // then we will again change the * to O
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        change(board,i,j);
                    }
                }
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='*') board[i][j]='O';
            }
        }
        
    }

// ************
// peak element
int findPeakElement(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<h){
            int m=(l+h)/2;
            if(nums[m]<nums[m+1]) l=m+1;
            else h=m;
        }
        return h;
    }



// aggressive cows
// low=0
// high=a[n-1]
// mid is minimum distance between two cows
#include <bits/stdc++.h>
using namespace std;
 
bool isPossible(int a[],int mid,int c,int n){
    int cowCount=1;
    int lastPos=a[0];
    for(int i=0;i<n;i++){
        if(a[i]-lastPos>=mid){
            cowCount++;
            if(cowCount==c) return true;
            lastPos=a[i];
        }
    }
    return false;
}
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int l=0;
        int h=a[n-1];
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(a,mid,c,n)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}  



// allocate minimum number of pages
// mid is maximum number of pages , given to a student
bool isPossible(int a[],int n,int m,int mid){
        int sum=0;
        int student=1;
        for(int i=0;i<n;i++){
            if(sum+a[i]<=mid){
                sum+=a[i];
            }
            else{
                student++;
                if(student>m || a[i]>mid) return false;
                sum=a[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int ans=-1;
        int sum=0;
        for(int i=0;i<N;i++) sum+=A[i];
        int l=0;
        int h=sum;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(A,N,M,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }




// Find position of an element in a sorted array of infinite numbers
// int l=0,h=1 then l=h , h=h*2 untill we find target<=h


//Bitonic array means it first increases then decreases



// count of smaller after self
// merge sort
// vector of pair with element and its index , as we will have to store the count in a index
// sort in descending order
void merge(vector<int> &ans,vector<pair<int,int>> &v,int l,int h,int m){
        vector<pair<int,int>> temp(h-l+1);
        int i=l;
        int j=m+1;
        int k=0;
        while(i<=m && j<=h){
            if(v[i].first>v[j].first){
                ans[v[i].second]+=h-j+1;
                temp[k++]=v[i++];
            }
            else temp[k++]=v[j++];
        }
        while(i<=m) temp[k++]=v[i++];
        while(j<=h) temp[k++]=v[j++];
        for(int t=l;t<=h;t++){
            v[t]=temp[t-l];
        }
    }
    void mergeSort(vector<int> &ans,vector<pair<int,int>> &v,int l,int h){
        if(l<h){
            int m=l+(h-l)/2;
            mergeSort(ans,v,l,m);
            mergeSort(ans,v,m+1,h);
            merge(ans,v,l,h,m);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});
        mergeSort(ans,v,0,v.size()-1);
        return ans;
    }



// first and last position in array
vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        low=0;
        high=nums.size()-1;
        int ans2=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans2=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        vector<int> v;
        v.push_back(ans);
        v.push_back(ans2);
        return v;
    }


// smallest letter greater than target
// Note that the letters wrap around.
char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0;
        int h=letters.size()-1;
        int ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(letters[m]>target){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        if(ans==-1) return letters[0];
        else return letters[ans];
    }



// minimum swaps to put number less than k together
// find count less than k
// move in window of count
// and find a window with maximum number less than k
// then count-maxi will be answer
int minSwap(int arr[], int n, int k) {
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k) count++;
        }
        int temp=0;
        for(int i=0;i<count;i++){
            if(arr[i]<=k) temp++;
        }
        int maxi=temp;
        int i=0;
        for(int j=count;j<n;j++){
            if(arr[i]<=k) temp--;
            if(arr[j]<=k) temp++;
            i++;
            maxi=max(temp,maxi);
        }
        return count-maxi;
    }


// operation will be same to conver sorted to the given array
// store in vector of pair as element and index
// sort 
int minSwaps(vector<int>&nums)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int num=v[i].first;
            int ind=v[i].second;
            if(i!=ind){
                ans++;
                swap(v[i],v[ind]);
                i--; // the element which came may not be at it's correct position
            }
        } 
        return ans;
    }


// rotated by k , find k
// index of pivot will be answer
int findKRotation(int arr[], int n) {
        int l=0;
        int h=n-1;
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(arr[m]>=arr[0]){
                l=m+1;
            }
            else{
                ans=m;
                h=m-1;
            }
        }
        return ans;
    }



// Search in an almost sorted array
// means element which should be at i , can now be present at i-1,i,i+1
// we will check in i-1,i,i+1
// and reduce search space by mid-2, or mid+2


 // find the pivot (comparing with first element)
 // then check in which half the element can be present
 int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int pivot=-1;
        while(l<h){
            int m=(l+h)/2;
            if(nums[m]>=nums[0]) l=m+1;
            else h=m;
        }
        pivot=l;
        if(nums[pivot]<=target && target<=nums[n-1]){
            l=pivot;
            h=n-1;
        }
        else{
            l=0;
            h=pivot-1;
        }
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target) h=m-1;
            else l=m+1;
        }
        return -1;
    }


// every element in the array except one appers twice find that element
int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<h){
            int m=(l+h)/2;
            if((m%2==0 && nums[m]==nums[m+1]) || (m%2!=0 && nums[m]==nums[m-1])){
                l=m+1;
            }
            else{
                h=m;
            }
        }
        return nums[h];
    }


// Given an array nums which consists of non-negative integers and an integer m, 
// you can split the array into m non-empty continuous subarrays.
// Write an algorithm to minimize the largest sum among these m subarrays
// l=maximum element
// h=sum of subarray
// mid=maximum sum of a subarray
int possibleSubarray(int mid,vector<int> &nums){
        int subcount=1;
        int curSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+curSum<=mid){
                curSum+=nums[i];
            }
            else{
                subcount++;
                curSum=nums[i];
            }
        }
        return subcount;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        int l=*max_element(nums.begin(),nums.end());
        int h=sum;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possibleSubarray(mid,nums)<=m){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }



// assume the first node is the last node
// when we go to next node then we assume it as to be the last
// and multiply the previous answer by 2
int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head){
            ans*=2;
            ans+=head->val;// head->val*2^0
            head=head->next;
        }
        return ans;
    }


// node to be deleted is given
// O(1) this will not work if node to be deleted is last


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a= a==NULL?headB:a->next;
            b= b==NULL?headA:b->next;
        }
        return a;
    }


bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL) return false;
        while(fast->next && fast->next->next){
            if(slow->next==fast->next->next) return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp=new ListNode(-1);
        ListNode* ans=temp;

        while(list1 and list2){
            if((list1->val)>(list2->val)){
                temp->next=list2;
                list2=list2->next;  
            }
            else{
                temp->next=list1;
                list1=list1->next;
            }
            temp=temp->next;
        }
        while(list1){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        while(list2){
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }
        return ans->next;
    }  


ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


// find first number then 2nd number 
// then multiply
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long mod=1e9+7;
  long long num1=0;
  long long num2=0;
  Node* p1=l1;
  Node* p2=l2;
  while(p1){
      num1=((num1*10)%mod +p1->data)%mod;
      p1=p1->next;
  }
  while(p2){
      num2=((num2*10)%mod +p2->data)%mod;
      p2=p2->next;
  }
  return (num1*num2)%mod;
}


ListNode* reverseList(ListNode* head) {
        ListNode* newHead=NULL;
        while(head){
            ListNode* temp=head->next;
            head->next=newHead;
            newHead=head;
            head=temp;
        }
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow){
            if(slow->val!=head->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }



// while(cur) while(cur->next && cur->val == cur->next->val)
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;
        while(cur){
            while(cur->next && cur->val==cur->next->val){
                cur->next=cur->next->next;
            }
            cur=cur->next;
        }
        return head;
    }


ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        while(head && head->val==val){
            head=head->next;
        }
        ListNode*cur=head;
        while(cur){
            while(cur->next && cur->next && cur->next->val==val){
                cur->next=cur->next->next;
            }
            cur=cur->next;
        }
        return head;
    }


ListNode* reverseList(ListNode* head) {
        ListNode* newHead=NULL;
        while(head){
            ListNode* temp=head->next;
            head->next=newHead;
            newHead=head;
            head=temp;
        }
        return newHead;
    }


// there are two methods
// first to count 0 , 1 and 2 then replace
// second if you dont want to replace
// create 6 nodes
// and attach 0 , 1 , 2

void insertAtTail(Node* &tail,Node* cur){ // pass by reference
        tail->next=cur;
        tail=cur; // pointing tail ahead
    }
    Node* segregate(Node *head) {
        
        Node* zeroHead=new Node(-1);
        Node* zeroTail=zeroHead;
        Node* oneHead=new Node(-1);
        Node* oneTail=oneHead;
        Node* twoHead=new Node(-1);
        Node* twoTail=twoHead;
        
        Node* cur=head;
        while(cur){
            if(cur->data==0){
                insertAtTail(zeroTail,cur);
            }
            else if(cur->data==1){
                insertAtTail(oneTail,cur);
            }
            else if(cur->data==2){
                insertAtTail(twoTail,cur);
            }
            cur=cur->next;
        }
        
        if(oneHead->next==NULL){
            zeroTail->next=twoHead->next;
        }
        else zeroTail->next=oneHead->next;
        
        oneTail->next=twoHead->next;
        twoTail->next=NULL;
        head=zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
        
    }




ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode();
        ListNode* dummy=temp;
        int carry=0;
        while((l1||l2) || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode* node=new ListNode(sum%10);
            carry=sum/10;
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
    


// add two numbers 2
// reverse then add


// flatten the linked list
Node* merge(Node* root,Node* next){
        if(root==NULL) return next;
        if(next==NULL) return root;
        Node* ans=new Node(-1);
        Node* temp=ans;
        while(root!=NULL && next!=NULL){
            if(root->data>next->data){
                temp->bottom=next;
                next=next->bottom;
                temp=temp->bottom;
            }
            else{
                temp->bottom=root;
                root=root->bottom;
                temp=temp->bottom;
            }
        }
        if(root) temp->bottom=root;
        else temp->bottom=next;
        
        return ans->bottom;
    }
Node *flatten(Node *root)
{
   if(root==NULL) return NULL;
   return merge(root,flatten(root->next));
}



// flatten a multilevel doubly linked list
// recursive function will return last node
Node* flatten_rec(Node* head){
        Node* cur=head;
        Node* last=head;
        while(cur){
            Node* child=cur->child;
            Node* next=cur->next;
            if(child){
                Node* tail=flatten_rec(cur->child);
                tail->next=next;
                if(next) next->prev=tail;
                cur->next=child;
                child->prev=cur;
                cur->child=NULL;
                cur=tail;
            }
            else cur=next;
            if(cur) last=cur;
        }
        return last;
    }
    Node* flatten(Node* head) {
        if(head) flatten_rec(head);
        return head;
    }




// merge k sorted lists
// compare class in priority queue
// put all first element of lists in min heap
// take and attach , push next of that
class cmp{
        public:
        bool operator()(const ListNode* a,const ListNode* b){
            return( a->val>b->val);
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lists.size();i++) if(lists[i]!=NULL) pq.push(lists[i]);
        while(!pq.empty()){
            ListNode* least=pq.top();
            pq.pop();
            temp->next=least;
            temp=temp->next;
            if(least->next) pq.push(least->next);
        }
        return dummy->next;
    }
};




// patition list
// separate number less than x and greater than x
// we make dummy nodes so we do not need to handle if head's position is changing
ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode(-1);
        ListNode* curLess=less;
        ListNode* greater=new ListNode(-1);
        ListNode* curGreater=greater;
        while(head){
            if((head->val)<x){
                curLess->next=head;
                curLess=curLess->next;
            }
            else{
                curGreater->next=head;
                curGreater=curGreater->next;
            }
            head=head->next;
        }
        curGreater->next=NULL;
        if(greater->next)
        curLess->next=greater->next;
        return less->next;;
    }



// remove all duplicates
// only distincts node's should be left
// make prev node , start with dummy
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev=dummy;
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
            }
            else prev=prev->next;
            head=head->next;
        }
        return dummy->next;
    }



// remove nth node from end 
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* slow=start;
        ListNode* fast=start;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
    } 




// reorder list 
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// find mid
// break into two list (2nd one should be reversed)
// then attach
ListNode* reverseList(ListNode* head) {
        ListNode* newHead=NULL;
        while(head){
            ListNode* temp=head->next;
            head->next=newHead;
            newHead=head;
            head=temp;
        }
        return newHead;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        ListNode* second=reverseList(slow->next);
        slow->next=NULL;
        while(second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }



// reverse from left to right
// two methods one is the simple one
// other one is this
ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next=head;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode* tail=prev->next;
        for(int i=0;i<right-left;i++){
            ListNode* temp=prev->next;
            prev->next=tail->next;
            tail->next=prev->next->next;
            prev->next->next=temp;
        }
        return dummy->next;
    }


// reverse nodes in k groups
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp=temp->next;
        }
        
        int count=0;
        ListNode* next=NULL;
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur!=NULL && count<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        if(cur!=NULL){
            head->next=reverseKGroup(cur,k);
        }
        return prev;
    }


// segregate even and odd
Node* divide(int N, Node *head){
        Node* even=new Node(-1);
        Node* evenP=even;
        Node* odd=new Node(-1);
        Node* oddP=odd;
        while(head){
            if((head->data)&1){
                oddP->next=head;
                oddP=head;
            }
            else{
                evenP->next=head;
                evenP=head;
            }
            head=head->next;
        }
        oddP->next=NULL;
        if(odd->next){
            evenP->next=odd->next;
        }
        return even->next;
    }



// find mid 
// separate two list's
// sort by recursion
// merge and return 
ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(left && right){
            if(left->val>right->val){
                temp->next=right;
                right=right->next;
                temp=temp->next;
            }
            else{
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }
        }
        while(left){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        }
        while(right){
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }






// minimum distance of every cell from any 0
// starting ans matrix with intmax and mark 0 element with zero
// store inexes of all zeroes in queue
// while q is not empty run the while loop
// and check if it can be updated update and push

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            if((i-1)>=0 && (ans[i][j]+1<ans[i-1][j])){
                ans[i-1][j]=ans[i][j]+1;
                q.push({i-1,j});
            }
            if((j-1)>=0 && (ans[i][j]+1<ans[i][j-1])){
                ans[i][j-1]=ans[i][j]+1;
                q.push({i,j-1});
            }
            if((i+1)<ans.size() && (ans[i][j]+1<ans[i+1][j])){
                ans[i+1][j]=ans[i][j]+1;
                q.push({i+1,j});
            }
            if((j+1)<ans[0].size() && (ans[i][j]+1<ans[i][j+1])){
                ans[i][j+1]=ans[i][j]+1;
                q.push({i,j+1});
            }
            q.pop();
        }
        return ans;
    }
    



//Given two strings s and t, return true if they are equal 
//when both are typed into empty text editors. 
//'#' means a backspace character.
bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!st1.empty())
                st1.pop();
            }
            else st1.push(s[i]);
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!st2.empty())
                st2.pop();
            }
            else st2.push(t[i]);
        }
        if(st1.size()!=st2.size()) return false;
        else{
            while(st1.size() && st2.size()){
                if(st1.top()==st2.top()){
                    st1.pop();
                    st2.pop();
                }
                else return false;
            }
        }
        return true;
    }



// we are given circular path of petrol pumps
// we need to start from any index of petrol pump and complete a circle
// arr given has petrol and distance to the next petrol pump
// we will take three variable start (will tell starting index)
// balance current extra petrol
// deficit is need (kami ) of petrol from start
// struct petrolPump
// {
//     int petrol;
//     int distance;
// };
int tour(petrolPump p[],int n)
    {
       int start=0;
       int balance=0;
       int deficit=0;
       for(int i=0;i<n;i++){
           balance+=p[i].petrol-p[i].distance;
           if(balance<0){
               deficit+=balance;
               start=i+1;
               balance=0;
           }
       }
       if(balance+deficit>=0) return start;
       else return -1;
    }



// number of days to wait after ith day to get warmer (greater ) temperature
vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        st.push({temperatures[n-1],n-1});
        vector<int> ans(n);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top().first<=temperatures[i]) st.pop();
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top().second-i;
            st.push({temperatures[i],i});
        }
        return ans;
    }



// deque
// push_back,push_front,pop_back,pop_front
// front , back , at


// evaluation of postfix(reverse polish notation)
// string to number -> stoi()
int evaluatePostfix(string exp)
    {
        stack<int> st;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='*'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(first*second);
        }
        else if(exp[i]=='/'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second/first);
        }
        else if(exp[i]=='+'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(first+second);
        }
        else if(exp[i]=='-'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second-first);
        }
        else st.push(exp[i]-'0');
    }
    return st.top();
    }



// two stack in single array
// inititally top1=-1, top2=size
// stack one will be filled from start 
// stack two will be filled from end
void twoStacks :: push1(int x)
{
    if(top2-top1>1){
        top1++;
        arr[top1]=x;
    }
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top2-top1>1){
        top2--;
        arr[top2]=x;
    }
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1>=0){
        int x=arr[top1];
        top1--;
        return x;
    }
    else return -1;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2<size){
        int x=arr[top2];
        top2++;
        return x;
    }
    else return -1;
}



// solve in leetcode
// get (get a particular key) and put (put in cache) , if full remove the least recently used
class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};



vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()) mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])==mp.end()) ans.push_back(-1);
            else ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }




// The span of the stock's price today is defined as the maximum number of consecutive days 
// (starting from today and going backward) for which the stock price was less than or equal to today's price.
// For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock 
// spans would be [1,1,1,2,1,4,6]
// we wil simply check if stack is empty means there is no next greater in left so i+1
// else i-st.top().second (index of next greater  in  left)
StockSpanner() {
        
    }
    int i=0;
    stack<pair<int,int>> st;
    int next(int price) {
        while(!st.empty() && st.top().first<=price) st.pop();
        int ans;
        if(st.empty()) ans=i+1;
        else ans=i-st.top().second;
        st.push({price,i});
        i++;
        return ans;
    }


// queue using stack 
// take two stack
// for making pop costlier
// push in st1 
// when want to pop
// transfer elements to st2
// its top will be the answer
// then again transfer to st1
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};




// if k duplicates are together remove them
// stack of char ,int (count of that element)
// st.top has same char increment it's count
// if count==k st.pop()
// now form the ans string 
string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }
            else{
                auto prev=st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            if(st.top().second==k) st.pop();
        }
        string ans="";
        while(!st.empty()){
            auto cur=st.top();
            st.pop();
            while(cur.second--) ans+=cur.first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }




// rotten oranges 
// 0 -> empty  , 1-> fresh orange , 2-> rotten
// rotten , rottens in four directions
// push all rotten in queue
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0,count=0,minutes=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int size=q.size();
            count+=size;
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int cx=x+dx[i];
                    int cy=y+dy[i];
                    if(cx<0 || cx>=n || cy<0 || cy>=m || grid[cx][cy]!=1 ) continue;
                    grid[cx][cy]=2;
                    q.push({cx,cy});
                }
            }
            if(!q.empty()) minutes++;
        }
        return (total==count)?minutes:-1;
    }



// stack using queue
// we can do this using 2 queue and 1 queue
// if we use 2 queue we can do it in two ways
// making push(optimal) costlier or making pop costlier
// making push costlier
// take two queue , q1 and q2 , push in q2 then push all element of q1 in q2 then swap 
// pop and top is simple
// OR we can do this with only one queue as well
// push in queue and for size -1 elements push the front again and pop
class MyStack {
public:
    // queue<int> q1;
    // queue<int> q2;
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // swap(q1,q2);
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // int ans=q1.front();
        // q1.pop();
        // return ans;
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        // return q1.front();
        return q.front();
    }
    
    bool empty() {
        // return q1.empty();
        return q.empty();
    }
};




// sum of minimum of every subarray
// iterate over every element and suppose it's minimum of a subarray
// but question of how many subarray
// we will calculate next smaller and prev smaller
// then we will calculate elements in left of that element then elemenst in right of that element
// total subarrays (left+1)*(right+1)
// cost v[i]*tota subarryas with that element minimum
// if have two equal element in the array ,then we will count subarrays twice
// therefore mark either in next smaller or prev smaller greater than or equal to in heights[st.top()]>=heights[i]
vector<int> nextSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> & heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=arr[i];
        vector<int> next=nextSmaller(v,n);
        vector<int> prev=prevSmaller(v,n);
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long int right=next[i]-i-1; 
            long long int left=i-prev[i]-1;
            if(next[i]==-1) right=n-i-1;
            if(prev[i]==-1) left=i;
            ans=(ans%mod+v[i]*(left+1)*(right+1))%mod;
        }
        return ans;
    }






// the celibrity problem
// celibrity knows no one and everyone knows celibrity
// {{0 1 0},
//  {0 0 0}, 
//  {0 1 0}}
// Brute force -> n^2 -> for(0 to no of person) {for( for checking if all elements of row zero ) for( column should be one except diagonal )} 
// Optimal 
// put every person in stack
// while( stack size is not 1)
// A=st.top() then pop , B=st.top() then pop()
// if(A knows B) push B
// if(B knows A) push A
// the last element left is potential answer 
int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++) st.push(i);
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]){
                st.push(b);
            }
            else st.push(a);
        }
        int potentialCelibrity=st.top();
        int count0=0;
        int count1=0;
        for(int i=0;i<n;i++){
            if(M[potentialCelibrity][i]==0) count0++;
            if(M[i][potentialCelibrity]==1) count1++;
        }
        if(count0==n && count1==n-1) return potentialCelibrity;
        else return -1;
    }





// is tree balanced
// every node should be balanced
// pair will store bool and height
pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        int dif=abs(left.second-right.second);
        if(left.first && right.first && dif<=1 ){
            return {true,max(left.second,right.second)+1};
        }
        else{
            return {false,max(left.second,right.second)+1};
        }
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }



// all path from root to leaf
void solve(TreeNode* root,vector<string> &ans,string s){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return ;
        }
        if(root->left) solve(root->left,ans,s+"->"+to_string(root->left->val));
        if(root->right) solve(root->right,ans,s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s=to_string(root->val);
        solve(root,ans,s);
        return ans;
    }



// sorted array to height balanced binary search tree
// take mid of the array make it root , then call another function 
TreeNode* solve(int start ,int end,vector<int> &nums){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(start,mid-1,nums);
        root->right=solve(mid+1,end,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid=(nums.size()-1)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(0,mid-1,nums);
        root->right=solve(mid+1,nums.size()-1,nums);
        return root;
    }



// diameter of the binary tree first element of the pair will store the dia and the other will store height
pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
    int diameter(Node* root) {
    
        return diameterFast(root).first;
        
    }



TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }


// height of a binary tree
int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }


// merge to binary tree
// if one node is null and the other is not null make the new trees node as the not null one
// if both are not null , sum of both the node as the new node
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;
        if(root1==NULL && root2!=NULL) return root2;
        if(root1!=NULL && root2==NULL) return root1;
        TreeNode* root=new TreeNode(root1->val+root2->val);
        root->left=mergeTrees(root1->left,root2->left);
        root->right=mergeTrees(root1->right,root2->right);
        return root;
    }


// root to leaf with given target sum
bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->val==targetSum && root->left==NULL && root->right==NULL) return true;
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }


// find the sum of nodes in range low and high
// the given tree is bst
// so we can further optimise it
// if low > root->val then in range nodes can only be in right part
// if high < root->val then in range nodes can only be in left part
int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high)+
        ((root->val>=low && root->val<=high)?root->val:0);
    }


// is the tree same
// traverse together
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return p==NULL&&q==NULL;
        // if(p==NULL && q==NULL) return true;
        // if(p==NULL && q!=NULL) return false;
        // if(p!=NULL && q==NULL) return false;
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool val= p->val==q->val;
        if(left && right && val) return true;
        else return false;
    }


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


// return true if root's data is sum of its left and right subtree
// first element of pair wil store other will store sum
// here we will have to handle another case of leaf node, as we have to ignore the leaf node 
pair<int,int> solve(Node* root){
        if(root==NULL){
            return {true,0};
        }
        if(root->left==NULL && root->right==NULL){
            return {true,root->data};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        int sum=left.second+right.second;
        if(left.first && right.first && sum==root->data) return {true,sum+root->data};
        else return {false,sum+root->data};
    }
    bool isSumTree(Node* root)
    {
         return solve(root).first;
    }


 // symmetric tree
 bool solve(TreeNode* first,TreeNode* second){
        if(first==NULL && second==NULL ) return true;
        if(first && second && first->val==second->val)
        return solve(first->left,second->right)&&solve(first->right,second->left);
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }


// store in queue
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* it=q.front();
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
                temp.push_back(it->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }



vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool f=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                int index=(f)?i:(size-i-1);
                TreeNode* cur=q.front();
                q.pop();
                temp[index]=cur->val;
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            ans.push_back(temp);
            f=!f;
        }
        return ans;
    }



// print left node's (except last ) , print leaf nodes , then right nodes (except last)
void traverseLeft(Node* root, vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else traverseLeft(root->right,ans);
    }
    void traverseRight(Node* root,vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return ;
        if(root->right){
            traverseRight(root->right,ans);
        }
        else traverseRight(root->left,ans);
        ans.push_back(root->data);
    }
    void traverseLeaf(Node* root,vector<int> &ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) ans.push_back(root->data);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        
        // if pass with the root and only one root present , then ans will have two roots
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);

        traverseRight(root->right,ans);
        
        return ans;
    }



// map of <hd , map<level,values>>
// queue of node and hd,level
vector<int> verticalOrder(Node *root)
    {
        // hd       level  node's value 
        map<int,map<int,vector<int>>> mp;
        vector<int> ans;
        if(root==NULL) return ans;
        
        //        node        hd  level
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int hd=temp.second.first;
            int lvl=temp.second.second;
            mp[hd][lvl].push_back(temp.first->data);
            if(temp.first->left) q.push({temp.first->left,{hd-1,lvl+1}});
            if(temp.first->right) q.push({temp.first->right,{hd+1,lvl+1}});
        }
        for(auto i:mp){
            for(auto j:i.second){
                for(auto cur:j.second){
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }


// make map of int ,int and update only when new hd comes
vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        //  hd  root'data
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop();  
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end())
            mpp[line] = node->data; 
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;
    }

// update everytime you see a new hd
vector <int> bottomView(Node *root) {
         vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop();  
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;
    }

// left view , maintain level and compare with vector of ans .size
void solve(Node * root,vector<int> &ans,int level){
    if(root==NULL ) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}

// right view, go to the right first
void solve(Node * root,vector<int> &ans,int level){
        if(!root) return;
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);

    }
    
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }


// diagonal traversal
// push root in queue
// in while loop
// move to right of front node
// push if left exist 
// put in ans then move right
vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(root==NULL) return ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       while(temp){
           if(temp->left) q.push(temp->left);
           ans.push_back(temp->data);
           temp=temp->right;
       }
   }
   return ans;
}





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




// given a binary tree , determine if it is height balanced
pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        int dif=abs(left.second-right.second);
        if(left.first && right.first && dif<=1 ){
            return {true,max(left.second,right.second)+1};
        }
        else{
            return {false,max(left.second,right.second)+1};
        }
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }



// BST iterator
// next (next inorder)
// hasNext

// push all left nodes in push all function
// if want next give the top and push all it's right(cur->right)
class BSTIterator {
    stack <TreeNode*> st;
public:
    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* cur=st.top();
        st.pop();
        pushAll(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};




// check if bst had dead end (no further nodes can be added)
// if min and max becomes true , return true (means there is a dead end)
bool solve(Node* root,int min,int max)
{
    if(root==NULL ) return false;
    if(min==max) return true;
    return solve(root->left,min,root->data-1) || solve(root->right,root->data+1,max);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root,1,INT_MAX);
}



// kth ancestor of a node
// root's data is node return root
// call in left and right
// if both null return null
// if one of them is not null
// decrement k , k==0 return root else return the one which is not null
Node* solve(Node* root,int &k ,int node){
    if(root==NULL) return NULL;
    if(root->data==node) return root;
    Node* left= solve(root->left,k,node);
    Node* right= solve(root->right,k,node);
    if(left==NULL && right!=NULL){
        k--;
        if(k==0) return root;
        else return right;
    }
    if(right==NULL && left!=NULL){
        k--;
        if(k==0) return root;
        else return left;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node) return -1;
    else
    return ans->data;
}



// if root is one of p and q return root
// call for left and right
// if getting answer from both the sides return root
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        else if(left!=NULL && right==NULL) return left;
        else if(left==NULL && right!=NULL) return right;
        else return NULL;
    }




// lca of bst
// if root ==null return null
// if both nodes on right go to the right , if both nodes at left , move left
// else return root
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else return root;
    }



vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* it=q.front();
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
                temp.push_back(it->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }



// maximum sum of non adjacent elements
// at every node there are two options we can take it or leave it
pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> temp={0,0};
            return temp;
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        pair<int,int> ans;
        ans.first=root->data+left.second+right.second;// including first, so taking excluding of left and right
        ans.second=max(left.first,left.second)+max(right.first,right.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        // max sum when includeing current , excluding
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }



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




// Predecessor and Successor 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp=root;
    while(temp){
        if(temp->key>key){
            suc=temp;
            temp=temp->left;
        }
        else temp=temp->right;
    }
    temp=root;
    while(temp){
        if(temp->key<key){
            pre=temp;
            temp=temp->right;
        }
        else temp=temp->left;
    }
}



// maintain a level
void solve(TreeNode* root,vector<int> &ans,int level){
        if(root==NULL) return ;
        if(ans.size()==level) ans.push_back(root->val);
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }


// return sum of left leaves(left nodes , which are on left of another node)
int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left && root->left->left==NULL && root->left->right==NULL){
            return root->left->val+sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }



// sum of nodes of longest path
// maintain maxsum, sum, len,maslen
void solve(Node* root,int sum,int &maxsum,int len,int &maxlen){
        if(root==NULL){
            if(len>maxlen){
                maxsum=sum;
                maxlen=len;
            }
            else if(len==maxlen){
                maxsum=max(maxsum,sum);
            }
            return ;
        }
        sum+=root->data;
        solve(root->left,sum,maxsum,len+1,maxlen);
        solve(root->right,sum,maxsum,len+1,maxlen);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum=0;
        int maxsum=0;
        int len=0;
        int maxlen=0;
        solve(root,sum,maxsum,len,maxlen);
        return maxsum;
    }




Node* solve(int &index,int in[],int post[],int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element=post[index];
        Node* root=new Node(element);
        int position=nodeToIndex[element];
        index--;
        // calling right recurstion first as index of postorder points there 
        root->right=solve(index,in,post,position+1,inorderEnd,n,nodeToIndex);
        root->left=solve(index,in,post,inorderStart,position-1,n,nodeToIndex);
        return root;
    }
Node *buildTree(int in[], int post[], int n) {
        map<int,int> nodeToIndex;
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
        int postOrderStart=n-1;
        return solve(postOrderStart,in,post,0,n-1,n,nodeToIndex);
}


// we want to increment index and want to reflect that in every call 
    // tc after using map => nlong + n =nlogn
    // sc = n of map , stack space = 
    Node* solve(int &index,int in[],int pre[],int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=pre[index];
        Node* root=new Node(element);
        int position=nodeToIndex[element];
        index++;
        root->left=solve(index,in,pre,inorderStart,position-1,n,nodeToIndex);
        root->right=solve(index,in,pre,position+1,inorderEnd,n,nodeToIndex);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // to get inorder index at O(1)
        map<int,int> nodeToIndex;
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
        int preOrderStart=0;
        return solve(preOrderStart,in,pre,0,n-1,n,nodeToIndex);
    }


// validate a bst
bool solve(TreeNode* root,long mini,long maxi){
        if(root==NULL) return true;
        if(root->val <=mini || root->val >=maxi){
            return false;
        }
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }




TreeNode* solve(vector<int> &pre,map<int,int> &postOrderMap,int &preIndex,int postStart,int postEnd){
        if(postStart>postEnd) return NULL;
        TreeNode* node =new TreeNode(pre[preIndex]);
        preIndex++;
        if(postStart==postEnd) return node;
        int postIndex=postOrderMap[pre[preIndex]];
        node->left=solve(pre,postOrderMap,preIndex,postStart,postIndex);
        node->right=solve(pre,postOrderMap,preIndex,postIndex+1,postEnd-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        map<int,int> postOrderMap;
        for(int i=0;i<post.size();i++) postOrderMap[post[i]]=i;
        int preIndex=0;
        return solve(pre,postOrderMap,preIndex,0,post.size()-1);
    }



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




// count bst nodes that lie int he given range
int getCount(Node *root, int l, int h)
    {
         if(root==NULL) return 0;
         if(root->data>=l && root->data<=h){
             return 1+getCount(root->left,l,h)+getCount(root->right,l,h);
         }
         else if(root->data<l && root->data<h){
             return getCount(root->right,l,h);
         }
         else if(root->data>l && root->data>h){
             return getCount(root->left,l,h);
         }
    }



// if cur's left exists
    // cur ka predecessor nikalo (left jaake right jaate jao)
    // then uske right ko cur ke right se connect karo 
    // and mark cur's right as it's left
    // and mark left as null
    // after that move cur to right
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        while(cur){
            if(cur->left){
                TreeNode* pred=cur->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }



// kth smallest element in bst
// maintain a count cur
// in inorder we get the sorted order ( access and check between left and right calls)
// call for left and if does not give -1 return left;
int solve(TreeNode* root,int k,int &cur){
        if(root==NULL) return -1;
        int left=solve(root->left,k,cur);
        if(left!=-1) return left;
        if(cur==k-1) return root->val;
        cur++;
        int right=solve(root->right,k,cur);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cur=0;
        return solve(root,k,cur);
    }



// maximum width binary tree
// find maximum width between any two existing nodes (in a level)
// if we mark the index , then the task is to subtract first and last and add 1
// children of i -> 2*i+1,2*i+2
// queue will be of pair of node , index
// subtracting the minimum of every level (first element) with index , to store in int
int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long int mini=q.front().second;
             int first,last;
            for(int i=0;i<size;i++){
                long long int cur_index=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=cur_index;
                if(i==size-1) last=cur_index;
                if(node->left){
                    q.push({node->left,cur_index*2+1});
                }
                if(node->right){
                    q.push({node->right,cur_index*2+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }



// minimum distance between any two nodes of a binary tree
// find the lca first, then find distance of the two nodes from lca
Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root==NULL) return NULL;
        if(root->data==p || root->data==q) return root;
        Node* left=lowestCommonAncestor(root->left,p,q);
        Node* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        else if(left!=NULL && right==NULL) return left;
        else if(left==NULL && right!=NULL) return right;
        else return NULL;
    }
    int solve(Node* root,int k,int dist){
        if(root==NULL) return -1;
        if(root->data==k) return dist;
        int left=solve(root->left,k,dist+1);
        if(left!=-1) return left;
        return solve(root->right,k,dist+1);
    }
    int findDist(Node* root, int a, int b) {
        Node* lca=lowestCommonAncestor(root,a,b);
        int distA=solve(lca,a,0);// 0 here is the current distance trvelled
        int distB=solve(lca,b,0);
        return distA+distB;
    }



// morrist traversal
// left check karo null hai kya
// hai toh push karke right
// else
// left jaake link banado sabki
// fir jab linke khudko point kare toh cur ko push kardo
vector < int > inorderTraversal(node * root) {
  vector < int > inorder;

  node * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      inorder.push_back(cur -> data);
      cur = cur -> right;
    } 
    else {
      node * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        inorder.push_back(cur -> data);
        cur = cur -> right;
      }
    }
  }
  return inorder;
}

vector < int > preorderTraversal(node * root) {
  vector < int > inorder;

  node * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      inorder.push_back(cur -> data);
      cur = cur -> right;
    } else {
      node * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        inorder.push_back(cur -> data);
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        cur = cur -> right;
      }
    }
  }
  return inorder;
}



// do a level order traversal 
// for each node for size-1 elements make it point to the next
// other  wise to null
Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
              Node* cur=q.front();
              q.pop();
              if(i<size-1){
                  Node* nex=q.front();
                  cur->next=nex;
              }
              else cur->next=NULL;
                
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            
        }
        return root;
    }



// two nodes are swapped in the bst 
// recover the corrrect bst
// maintain prev,first,middle(second),last pointers
// inorder gives sorted elements
// after calling left recursion
// check if prev exists and prev->val>root->val (wrong order)
// then check if it's the first time wrong order is yes make first=prev and middle=root other  wise
// last =root
// if last is not null , swap last  and first (inorder gives sorted order , only swapping of first and last can maintain the right order)
// other wise swap first and middle
class Solution {
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev){
            if(prev->val>root->val){
                if(first==NULL){
                    first=prev;
                    middle=root;
                }
                else{
                    last=root;
                }
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=NULL;
        first=NULL;
        middle=NULL;
        last=NULL;
        inorder(root);
        if(last){
            swap(first->val,last->val);
        }
        else swap(first->val,middle->val);
    }
};



vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool f=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                int index=(f)?i:(size-i-1);
                TreeNode* cur=q.front();
                q.pop();
                temp[index]=cur->val;
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            ans.push_back(temp);
            f=!f;
        }
        return ans;
    }





// hidden cameras
// we have to place minimum cameras in nodes so that every node is covered 
// (a camera looks over parent and it's children)
// we will check from bottom (post order)
// process after calculating left and right
// first check if any of the children want then camera , if yes then increase and return provide
// other wise if any of them provide , then return 'ok' , that means this is covered
// if both the child nodes are 'ok' return 'want'

// at last check if the root itself , want a camera then increase 
string solve(TreeNode* root,int &numberOfCameras){
        if(root==NULL) return "ok";
        string left=solve(root->left,numberOfCameras);
        string right=solve(root->right,numberOfCameras);
        if(left=="want" || right=="want"){
            numberOfCameras++;
            return "provide";
        }
        else if(left=="provide" || right=="provide"){
            return "ok";
        }
        else return "want";
    }
    int minCameraCover(TreeNode* root) {
        int numberOfCameras=0;
        if(solve(root,numberOfCameras)=="want") numberOfCameras++;
        return numberOfCameras;
    }




// binary tree maximum path
// any path where nodes can come in the sequence at most 1
// we are returning the maximum sum of either the left or right part
// and at current node we are finding maximum of left+right+root->valid
int solve(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int left=max(0,solve(root->left,ans));
        int right=max(0,solve(root->right,ans));
        ans=max(ans,left+right+root->val);
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }




// binary tree to doubly linked list
// inorder
// left will act as previous and right as next
// maintain a previous and make the first node as head
// point root's left to prev and prev's right to root
void solve(Node* root,Node* &prev,Node* &head){ // pass both by reference
        if(root==NULL) return ;
        solve(root->left,prev,head);
        if(prev==NULL) head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        solve(root->right,prev,head);
    }
    Node * bToDLL(Node *root)
    {
        Node* prev=NULL;
        Node* head=NULL;
        solve(root,prev,head);
        return head;
    }



// bst from preorder
// maintain a bound and iterate in the preorder and make nodes
TreeNode* build(vector<int> &preorder,int &i,int bound){
        if(i==preorder.size() || preorder[i]>bound) return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }




// one approach can call valid bst for every node
// OPTIMAL->
// largest bst in a binary tree
// for every node maintain , maximum , minimum, and maximum size bst, below and with this
// if root is null max will be INT_MIN , min will be INT_MAX
// calulate left and right
// if bst (left ka maximum se bada root, right ke minimum se chota root)
// min will be minimum of root->val and left minimum
// max will be maximum of root->val and right maximum
// max size will be right ka + left ka +1
// else if it is not a bst , from this it cannot be our answer
// so we will return max as INT_MAX , min as INT_MIN and maxSize as max of left and right
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};



// median of a bst
// 1st method store in array
// 2nd find height , if even move with a previous in inorder and find the median
// 3rd in constant space


// maintain a prev and do inorder
void solve(TreeNode* root,int &mini,TreeNode* &prev){
        if(root==NULL) return;
        solve(root->left,mini,prev);
        if(prev==NULL){
            prev=root;
        }
        else{
            mini=min(mini,root->val-prev->val);
            prev=root;
        }
        solve(root->right,mini,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        TreeNode* prev=NULL;
        solve(root,mini,prev);
        return mini;
    }



vector<int> verticalOrder(Node *root)
    {
        // hd       level  node's value 
        map<int,map<int,vector<int>>> mp;
        vector<int> ans;
        if(root==NULL) return ans;
        
        //        node        hd  level
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int hd=temp.second.first;
            int lvl=temp.second.second;
            mp[hd][lvl].push_back(temp.first->data);
            if(temp.first->left) q.push({temp.first->left,{hd-1,lvl+1}});
            if(temp.first->right) q.push({temp.first->right,{hd+1,lvl+1}});
        }
        for(auto i:mp){
            for(auto j:i.second){
                for(auto cur:j.second){
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }





// decode string
// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// if digit calculate num
// if alpha add in res
// if opening push both and update to zero
// if closing , add res nums.top()-1 times and add chars .top from start
// then pop both
string decodeString(string s) {
        stack<int> nums;
        stack<string> chars;
        string res="";
        int num=0;
        for(auto c:s){
            if(isdigit(c)) num=num*10+c-'0';
            else if(isalpha(c)) res+=c;
            else if(c=='['){
                nums.push(num);
                chars.push(res);
                num=0;
                res="";
            }
            else if(c==']'){
                string temp=res;
                for(int i=0;i<nums.top()-1;i++){
                    res+=temp;
                }
                res=chars.top()+res;
                nums.pop();
                chars.pop();
            }
        }
        return res;
    }



// flood fill
void dfs(vector<vector<int>>& image, int sr, int sc,int newColor,int rows,int cols,int source)
    {
        if(sr<0 || sr>=rows || sc<0 || sc>=cols)
            return;
        else if(image[sr][sc]!=source)
            return;
        
        image[sr][sc] = newColor;
        
        dfs(image,sr-1,sc,newColor,rows,cols,source);  
        dfs(image,sr+1,sc,newColor,rows,cols,source);   
        dfs(image,sr,sc-1,newColor,rows,cols,source);  
        dfs(image,sr,sc+1,newColor,rows,cols,source);   
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc]; 
        dfs(image,sr,sc,newColor,rows,cols,source);
        return image;
    }


// graph 
// to store in adjacency list space -> n+2e (n=no. of nodes, e =no of edges) 
// if weights are also stored -> n+2e+2e

// bfs
vector < int > bfsOfGraph(int V, vector < int > adj[]) {
      vector < int > bfs;
      vector < int > vis(V, 0);
      queue < int > q;
      q.push(0);
      vis[0] = 1;
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it: adj[node]) {
          if (!vis[it]) {
            q.push(it);
            vis[it] = 1;
          }
        }
      }

      return bfs;
    }

// dfs
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
    vector<int>dfsOfGraph(int V, vector<int> adj[]){
        vector<int> storeDfs; 
        vector<int> vis(V+1, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) dfs(i, vis, adj, storeDfs); 
      }
        return storeDfs; 
    }



// no of islands -> dfs
void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return; 
        if(grid[i][j]=='0') return;
        if(vis[i][j]!=-1) return ;
        vis[i][j]=1;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }




// rat in a maze problem
void solve(vector<string> &ans,string s,int i,int j,vector<vector<int>> &m,int n,vector<vector<int>> &vis){
        if(i==n-1 && j==n-1 ){
            ans.push_back(s);
            return;
        }
        if(i>=n || i<0 || j>=n || j<0 || m[i][j]==0 || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        solve(ans,s+'D',i+1,j,m,n,vis);
        solve(ans,s+'U',i-1,j,m,n,vis);
        solve(ans,s+'R',i,j+1,m,n,vis);
        solve(ans,s+'L',i,j-1,m,n,vis);
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        if(m[n-1][n-1]==0) return ans;
        string s="";
        vector<vector<int>> vis(n,vector<int>(n,0));
        solve(ans,s,0,0,m,n,vis);
        return ans;
    }



// find any one and run dfs on it while storing the nodes then break
    // now from the nodes in queue run bfs and find minimum distance
    void dfs(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &vis,queue<pair<int,int>> &q){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || vis[x][y]!=-1 || grid[x][y]==0) return;
        vis[x][y]=1;
        q.push({x,y});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            dfs(cx,cy,grid,vis,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        bool f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,q);
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        int dist=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            dist++;
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> temp=q.front();
                int x=temp.first;
                int y=temp.second;
                q.pop();
                for(int j=0;j<4;j++){
                    int cx=x+dx[j];
                    int cy=y+dy[j];
                    if(cx<0 || cy<0 || cx>=n || cy>=m || vis[cx][cy]==1) continue;
                    vis[cx][cy]=1;
                    if(grid[cx][cy]==1) return dist-1;
                    q.push({cx,cy});
                }
            }
        }
        return -1;
    }



// steps by knight 
// minimum steps to react target -> bfs
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
    {
        int ans=0;
        int s1=KnightPos[0]-1;
        int s2=KnightPos[1]-1;
        int d1=TargetPos[0]-1;
        int d2=TargetPos[1]-1;
        vector<vector<int>> vis(N,vector<int>(N,-1));
        if(s1==d1 && s2==d2) return 0;
        queue<pair<int,int>> q;
        q.push({s1,s2});
        int dx[]={2,2,-2,-2,1,1,-1,-1};
        int dy[]={1,-1,1,-1,2,-2,2,-2};
        bool f=0;
        while(!q.empty()){
            ans++;
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(int i=0;i<8;i++){
                    int cx=x+dx[i];
                    int cy=y+dy[i];
                    if(cx<0 || cy<0 || cx>=N || cy>=N || vis[cx][cy]!=-1) continue;
                    if(cx==d1 && cy==d2) return ans;
                    vis[cx][cy]=1;
                    q.push({cx,cy});
                }
            }
        }
        return -1;
    }





// cycle detection in undirected
// dfs -> maintain parent to differentiate between next and previous node
bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkForCycle(it, node, vis, adj))
            return true;
        } else if (it != parent)
          return true;
      }

      return false;
    }
    bool isCycle(int V, vector < int > adj[]) {
      vector < int > vis(V + 1, 0);
      for (int i = 0; i < V; i++) {
        if (!vis[i]) {
          if (checkForCycle(i, -1, vis, adj)) return true;
        }
      }

      return false;
    } 


// bfs -> queue will be of node and parent
bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V - 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
    }



// for undirected graph
// dfs discussed above will not work
// as we can visit same node if direction is same
// maintain vis and dfsvis(if the node is visited in the current movement)
bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }
    bool isCyclic(int N, vector < int > adj[]) {
      int vis[N], dfsVis[N];
      memset(vis, 0, sizeof vis);
      memset(dfsVis, 0, sizeof dfsVis);

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          if (checkCycle(i, adj, vis, dfsVis)) {
            return true;
          }
        }
      }
      return false;
    }




// disjoint set
// given two nodes tell if belong to same component or not
// findPar(), Union()
// we will maintain a rank (initially rank will be zero of all the nodes)
// if attaching two same rank guys , rank of the node to which we are attaching should increase
// when rank is diffent attach smaller to larger (no need to change the rank)
void makeSet(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int findPar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findPar(parent[node]);
}
void union(int u,int v){
    u=findPar(u);
    v=findPar(v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    } 
}




// find eventual safe state
// find state from where we can reach to terminal node (without entering in loop)
// find how many are in cycle using detect cycle in directed graph
bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &dfsVis,vector<bool>& present_cycle){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,dfsVis,present_cycle)){
                    return present_cycle[node]=true;
                }
            }
            else if(dfsVis[it]) return present_cycle[node]=true;
        }
        dfsVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        vector<bool> present_cycle(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,graph,vis,dfsVis,present_cycle);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!present_cycle[i]) ans.push_back(i);
        }
        return ans;
    }




// strongly connected comoponent (directed graph)
// Kosaraju's Algorithm
// from every node of that component we can reach to every other node
    // find toposort of the graph
    // transpose the graph
    // then run dfs according to topo sort
    void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis,st);
        }
        st.push(node);
    }
    void revdfs(int node,vector<int> transpose[],vector<int> &vis){
        vis[node]=1;
        for(auto it:transpose[node]){
            if(!vis[it]) revdfs(it,transpose,vis);
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++) if(!vis[i]) dfs(i,adj,vis,st);
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                transpose[it].push_back(i);
            }
        }
        int ans=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                ans++;
                revdfs(node,transpose,vis);
            }
        }
        return ans;
    }



// minutes needed to inform parent +   max time needed by childrens
    int dfs(vector<int> adj[],int node,vector<int> &informTime){
        int maxi=0;
        for(auto it:adj[node]){
            maxi=max(maxi,dfs(adj,it,informTime));
        }
        return maxi+informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        return dfs(adj,headID,informTime);
    }




// given matrix of 0 and 1 , find a zero such that distance of that from the nearest one is maximised
// go from 1 to zero , put all one in queue
// and run dfs
int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        bool one=false,zero=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) one =true;
                if(grid[i][j]==0) zero=true;
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        if(!one || !zero ) return -1;
        int ans=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int cx=x+dx[i];
                    int cy=y+dy[i];
                    if(cx<0 || cy<0 || cx>=grid.size() || cy>=grid[0].size() || grid[cx][cy]==1) continue;
                    grid[cx][cy]=1;
                    q.push({cx,cy});
                }
            }
            if(!q.empty()) ans++;
        }
        return ans;
    }




// bipartite graph
// graph which can be coloured using 2 colors
// bfs , if any componenet gives false then the answer is false
// maintain a color array
bool bipartiteBfs(int node,vector<int> adj[],vector<int> &color){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it:adj[temp]){
                if(color[it]==-1) {
                    color[it]=1-color[temp];
                    q.push(it);
                }
                else if(color[it]==color[temp]) return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(bipartiteBfs(i,adj,color)==false) return false;
            }
        }
        return true;
    }


// dfs
// maintain color
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}




// first task is dependent on the second one 
// detect cylce in directed graph
bool detectCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(detectCycle(it,adj,vis,dfsvis)==true) return true;
            }
            else if(dfsvis[it]) return true;
        }
        dfsvis[node]=0;
        return false;
    }
    bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) if(detectCycle(i,adj,vis,dfsvis)==true) return false;
        }
        return true;
    }



// find the city , from which we can visit smallest number of cities under the given distance
// floyyd warshall -> all pair shortes path
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++){ // k is our pivot
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && (dist[i][k]+dist[k][j])<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int ans;
        int cityCount=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) count++;
            }
            if(cityCount>=count){
                ans=i;
                cityCount=count;
            }
        }
        return ans;
    }




// floyd warshall
// all pair shortest path
// mark diagonal elements as zero
// rest all as int max
// now n^3 loop (1st one for pivot , i.e if we can go through this pivot with less distance)
void shortest_distance(vector<vector<int>>&matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) matrix[i][j]=0;
                else if(matrix[i][j]==-1) matrix[i][j]=INT_MAX;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX && (matrix[i][k]+matrix[k][j]<matrix[i][j])){
                        matrix[i][j]=matrix[i][k]+matrix[k][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==INT_MAX) matrix[i][j]=-1;
            }
        }
    }




// mst using kruskals
// first transfer adj to all edges list
// then sort according to weigth
// then iterate on this edges 
// if have different parent , add weith to answer
    int findPar(int node,vector<int> &parent){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node],parent);
    }
    void Union(int u,int v,vector<int> &rank,vector<int> &parent){
        u=findPar(u,parent);
        v=findPar(v,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        } 
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                v.push_back({it[1],{i,it[0]}});
                
            }
        }
        vector<int> rank(V,0);
        vector<int> parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(findPar(v[i].second.first,parent)!=findPar(v[i].second.second,parent)){
                ans+=v[i].first;
                Union(v[i].second.first,v[i].second.second,rank,parent);
            }
        }
        return ans;
    }




// topological sort
// can only be possible of directed acyclic graph
// if u->v is a edge then u always appears before v

// using dfs -> n+e (tc)
// run dfs and in every node if not visited
// put in answer after recursively calling all it's adjacent
// then reverse the answer array
void solve(int i,vector<int> adj[],vector<int> &vis,vector<int> &ans,int V){
        vis[i]=1;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                solve(it,adj,vis,ans,V);
            }
        }
        ans.push_back(i);
     
    }
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<int> vis(V+1,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(i,adj,vis,ans,V);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


// using bfs
// maintain indegree and push all indegree node's of zeros to the queue
// not run bfs while queue is not empty , and whenever go to adjacent reduce indegree and check if zero
vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
        vector<int> indegree(N, 0); 
        for(int i = 0;i<N;i++) {
            for(auto it: adj[i]) {
                indegree[it]++; 
            }
        }
        
        for(int i = 0;i<N;i++) {
            if(indegree[i] == 0) {
                q.push(i); 
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            topo.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it); 
                }
            }
        }
        return topo;
    }





// dijkstra is not possible in a graph with negative cycle
// make a distTo vector
// iterate over all edges , n-1 times , and update if possible
// run one more time for check , if yet it any edge is getting relaxed , means graph has a negative cycle
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
        vector<int> distTo(n,1e7);
        for(int i=1;i<=n-1;i++){
            for(auto it:edges){
                if(distTo[it[1]]>distTo[it[0]]+it[2]){
                    distTo[it[1]]=distTo[it[0]]+it[2];
                }
            }
        }
        bool f=0;
        for(auto it:edges){
            if(distTo[it[1]]>distTo[it[0]]+it[2]){
                f=1;
                break;
            }
        }
        if(f) return 1;
        else return 0;
    }




// maintain stops array , which will contain stops required to reach
// priority will now also contain stops
// if distance is more than stored distance , still it can be answer 
// check if new stops is less than stored stops , if yes push

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> v[n];
        for(int i=0;i<flights.size();i++){
            v[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> distTo(n,INT_MAX);
        vector<int> stops(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > pq;
        stops[src]=0;
        pq.push({0,src,stops[src]});
        while(!pq.empty()){
            int dist=pq.top()[0];
            int node=pq.top()[1];
            int curStops=pq.top()[2];
            pq.pop();
            if(node==dst) return dist;
            if(curStops==k+1) continue;
            for(auto it:v[node]){
                int nextNode=it.first;
                int nextDist=it.second;
                int nextStops=curStops+1;
                if(distTo[nextNode]>dist+nextDist){
                    distTo[nextNode]=dist+nextDist;
                    stops[nextNode]=nextStops;
                    pq.push({distTo[nextNode],nextNode,nextStops});
                }
                else if(nextStops<stops[nextNode]){
                    pq.push({nextDist+dist,nextNode,nextStops});
                }
            }
        }
        return -1;
    }




// dijkstra -> single source shortest path
// vector<pair<int,int>> v[V] -> for each vertex , number of vertex connected with edges
// min heap
// distTo vector
// update if possible
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<pair<int,int>> v[V];
        for(int i=0;i<V;i++){
            // v[i].push_back({adj[i][0],adj[i][1]});
            for(auto cur:adj[i]){
                v[i].push_back({cur[0],cur[1]});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        vector<int> distTo(V,INT_MAX);
        distTo[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:v[node]){
                int next=it.first;
                int nexdis=it.second;
                if(nexdis+dist<distTo[next]){
                    distTo[next]=dist+nexdis;
                    pq.push({distTo[next],next});
                }
            }
        }
        return distTo;
    }




// most stones removed from same row or column
// make a dsu of n size
// run two for loops and if any of the row or column matches, union the indexes
// after that check , how many stones have same parent , that will imply then number of components
// removed stones = n-numberOfComponents(one stone of every componenet will remain)
int findPar(int node,vector<int> &parent){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node],parent);
    }
    void Union(int u,int v,vector<int> &rank,vector<int> &parent){
        u=findPar(u,parent);
        v=findPar(v,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[u]=v;
            rank[v]++;
        } 
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j,rank,parent);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(findPar(i,parent)==i) count++;
        }
        return n-count;
    }





// snake and ladder of n^n blocks
// bfs algo
// maintain a visited and a queue
// find index positions of number in snake and ladder
pair<int,int> findPosition(int cx,int n){
        int i=n-((cx-1)/n) -1;
        int j=(i%2==n%2)?(n-((cx-1)%n)-1):(cx-1)%n;
        return {i,j};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        q.push(1);
        int steps=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int k=1;k<=6;k++){
                    int cx=x+k;
                    if(cx>n*n) break;
                    pair<int,int> p=findPosition(cx,n);
                    int i=p.first;
                    int j=p.second;
                    if(vis[i][j]) continue;
                    vis[i][j]=1;
                    if(board[i][j]==-1) q.push(cx);
                    else q.push(board[i][j]);
                }
            }
            steps++;
        }
        return -1;
    }






// alien dictionary
// given sorted words 
// we have to return the order of alphabets in their language
// for every consecutive words , because of the first unmatching char first word comes before then second
// link those words in graph
// now find topo sort
void dfs(int node,vector<vector<int>> &g,vector<int> &vis,string &ans){
        vis[node]=1;
        for(auto it:g[node]){
            if(!vis[it]) dfs(it,g,vis,ans);
        }
        ans=ans+(char)(node+'a');
    }
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> g(K);
        for(int i=0;i<N-1;i++){
            string word1=dict[i];
            string word2=dict[i+1];
            for(int j=0;j<word1.length()&&j<word2.length();j++){
                if(word1[j]!=word2[j]){
                    g[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        vector<int> vis(K,0);
        string ans="";
        for(int i=0;i<K;i++){
            if(!vis[i]){
                dfs(i,g,vis,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }




// longest increasing path in matrix
// make a 2d dp and check for every index , maximum path we can get from here
int dfs(int x,int y,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(dp[x][y]) return dp[x][y];
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int ans=1;
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(cx<0 || cy<0 || cx>=matrix.size() || cy>=matrix[0].size()) continue;
            if(matrix[cx][cy]<=matrix[x][y]) continue;
            ans=max(ans,1+dfs(cx,cy,matrix,dp));
        }
        return dp[x][y]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }




// given a binary 2d binary matrix
// we can change atmost a zero to one and get the largest size of island
// firstly change all island to it's id and store <id , area> in the map
// then again run 2 for loops , check if it is zero and converting it will give us how much area 
void dfs(int x,int y,vector<vector<int>> &grid,int id,int &count){
        if(x<0 || y<0 || x>=grid.size() || y>=grid.size()) return ;
        if(grid[x][y]>1 || grid[x][y]==0) return ;
        count++;
        grid[x][y]=id;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            dfs(cx,cy,grid,id,count);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        //  id  area
        map<int,int> mp;
        int n=grid.size();
        int id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(i,j,grid,id,count);
                    mp[id]=count;
                    id++;
                }
            }
        }
        int ans=INT_MIN;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int sum=0;
                    set<int> s;
                    for(int k=0;k<4;k++){
                        int cx=i+dx[k];
                        int cy=j+dy[k];
                        if(cx<0 || cy<0 || cx>=n || cy>=n || grid[cx][cy]==0) continue;
                        if(s.find(grid[cx][cy])!=s.end()) continue;
                        s.insert(grid[cx][cy]);
                        sum+=mp[grid[cx][cy]];
                    }
                    ans=max(ans,sum+1);
                }
            }
        }
        return ans==INT_MIN?n*n:ans;
    }




// number of spanning tree
// kirchoffs matrix tree theorem
// make a matrix , n=m=no of vertices
// if i!=j , if i and j adjacent m[i][j]=-1 , not adjacent m[i][j]=0
// if i==j , m[i][j]=degree if i
// then delete any row and any column
// take determinant of remaing matrix




// three array 
// key -> which will store the weight of connected
// parent -> paretn of the node
// mstSet -> is part of mst
// priority queue -> pair<int,int> -> weight and node 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,m;
    cin >> N >> m;
    vector<pair<int,int> > adj[N]; 
    int a,b,wt;
    for(int i = 0; i<m ; i++){
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }   
    int parent[N];   
    int key[N];   
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) key[i] = INT_MAX, mstSet[i] = false; 
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        mstSet[u] = true; 
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}




// given two jugs , want to know weather it is possible measure target sum
// we are effectively having one judge with capacity equal to it's sum of both jar's
// we can basically increase the water by x, y and decrease by y
// bfs -> tc=(total capacity)+e
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity;
        int y=jug2Capacity;
        int z=targetCapacity;
        if(z>x+y) return false;
        map<int,int> vis;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int dx[]={x,-x,y,-y};
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(a==z) return true;
            for(int i=0;i<4;i++){
                int ca=a+dx[i];
                if(ca<0 || ca>x+y || vis.find(ca)!=vis.end()) continue;
                vis[ca]=1;
                q.push(ca);
            }
        }
        return false;
    }




// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// push the starting word in queue
// now iterate on this , try to change with every char
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> mp;
        for(int i=0;i<wordList.size();i++) mp[wordList[i]]++;
        queue<string> q;
        q.push(beginWord);
        if(mp.find(endWord)==mp.end()) return 0;
        int ans=0;
        while(!q.empty()){
            ans++;
            int size=q.size();
            while(size--){
                string cur=q.front();
                q.pop();
                for(int i=0;i<cur.length();i++){
                    string temp=cur;
                    for(int j=0;j<26;j++){
                        temp[i]=j+'a';
                        if(mp.find(temp)==mp.end()) continue;
                        if(temp==endWord) return ans+1;
                        q.push(temp);
                        mp.erase(temp);
                    }
                }
            }
        }
        return 0;
    }




int climbStairs(int n) {
        // if(n<0) return 0;
        // if(n==0) return 1;
        // if(n==1) return 1;
        // return climbStairs(n-1)+climbStairs(n-2);
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }



// when number is even , number of set bit is same as number of set bit in half of the number
    // when number is odd , nuber of set bit is prev +1 -> prev=(i-1)/2+1 ==>i/2+1(for odd)
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i&1){
                // dp[i]=dp[i/2]+1;
                dp[i]=dp[i-1]+1;
            }
            else dp[i]=dp[i/2];
        }
        return dp;
    }



// dp
// tabulation -> bottom up
// memoization -> top down

// fibonacci (dp)
// tc=n,sc=n
// tabulation -> bottom up (try go from the base case)
// space optimized
// prev and prev2
for(int i=2;i<=n;i++){
    cur=prev+prev2;
    prev2=prev;
    prev=cur;
}
ans =prev;

// try represent problem in terms of index
// do all possible stuffs on that index acc. to problem
// sum of all suffs -> count all ways
// min (of all stuffs) -> minimmum



// can't rob continuout houses
int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int cur=max(prev2+nums[i],prev);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }



// first and last are adjacent
// first and last will not be together
    // leave the last and then leave the first , max of both
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size()-1;i++){
            int cur=max(prev2+nums[i],prev);
            prev2=prev;
            prev=cur;
        }
        int ans1=prev;
        
        prev=nums[1];
        prev2=0;
        for(int i=2;i<nums.size();i++){
            int cur=max(prev2+nums[i],prev);
            prev2=prev;
            prev=cur;
        }
        int ans2=prev;
        
        return max(ans1,ans2);
    }




// we are given a n length , we can cut it with x , y and z 
// we have to maximize cuts
int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i>=x && dp[i-x]!=-1){ // check if i>=x and can we cut i-x (dp[i-x])
                dp[i]=max(dp[i],1+dp[i-x]);
            }
            if(i>=y && dp[i-y]!=-1){
                dp[i]=max(dp[i],1+dp[i-y]);
            }
            if(i>=z && dp[i-z]!=-1){
                dp[i]=max(dp[i],1+dp[i-z]);
            }
        }
        return dp[n]<=0?0:dp[n];
    }




int solve(int *arr,int ind,vector<int> &dp){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=arr[ind]+solve(arr,ind-2,dp);
        int notpick=solve(arr,ind-1,dp);
        return dp[ind]=max(pick,notpick);
    }
    int findMaxSum(int *arr, int n) {
       // vector<int> dp(n+1,-1);
       // return solve(arr,n-1,dp
       
       // dp[0]=0;
       // dp[1]=arr[0];
       // for(int i=2;i<=n;i++){
       //     dp[i]=max(dp[i-2]+arr[i-1],dp[i-1]);
       // }
       // return dp[n];
       
       int prev=arr[0];
       int prev2=0;
       for(int i=2;i<=n;i++){
           int cur=max(prev2+arr[i-1],prev);
           prev2=prev;
           prev=cur;
       }
       return prev;
       
    }




// day cross task matrix is given can't perform same task in consecutive days
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for(int day = 1; day < n; day++) {
    for(int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for(int task = 0; task <= 2; task++) {
        if(task!=last){
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }
  }
  return dp[n - 1][3];
}




// given a vector of strings , we have to tell largest number of stings in which there are atmost m 0's and n 1's
// we have two options to include the current string in ans or not 
    vector<vector<vector<int>>> dp;
    int countZeros(vector<string> &strs,int index){
        int count=0;
        for(int i=0;i<strs[index].size();i++){
            if(strs[index][i]=='0') count++;
        }
        return count;
    }
    int solve(int index,int m,int n,vector<string>& strs){
        if(index==strs.size()) return 0;
        if(dp[index][m][n]!=-1) return dp[index][m][n];
        int zeros=countZeros(strs,index);
        int ones=strs[index].size()-zeros;
        if(m>=zeros && n>=ones)
            return dp[index][m][n]=max(1+solve(index+1,m-zeros,n-ones,strs),solve(index+1,m,n,strs));
        else return dp[index][m][n]=solve(index+1,m,n,strs);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size()+1,vector<vector<int>>(m+1,vector<int> (n+1)));
        // return solve(0,m,n,strs);
        for(int i=1;i<=strs.size();i++){
            int zeros=countZeros(strs,i-1);
            int ones=strs[i-1].size()-zeros;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(j>=zeros && k>=ones)
                    dp[i][j][k]=max(1+dp[i-1][j-zeros][k-ones],dp[i-1][j][k]);
                    else dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        return dp[strs.size()][m][n];
    }





// after reaching n-1,n-1 , we can again go to 0,0
    // it is same as two person goint to end
    // i1,j1,i2,j2 => i1+j1=i2+j2  =>  dp[i][j1][j2]
    int solve(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        int i1=i;
        int i2=i1+j1-j2;
        if(i>=grid.size() || i2>=grid.size() || j1>=grid[0].size() || j2>=grid[0].size()) return -1e8;
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1) return INT_MIN;
        if(i1==grid.size()-1 && j1==grid.size()-1) return grid[i][j1];
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        if(j1==j2 && i1==i2) ans+=grid[i][j1];
        else ans+=grid[i1][j1]+grid[i2][j2];
        int value=max(solve(i+1,j1,j2,grid,dp),solve(i+1,j1,j2+1,grid,dp));
        value=max(value,solve(i,j1+1,j2+1,grid,dp));
        value=max(value,solve(i,j1+1,j2,grid,dp));
        ans+=value;
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,solve(0,0,0,grid,dp));
    }





// i (row will be same for both)
    int solve(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()){
            return -1e8;
        }
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                int value=0;
                if(j1==j2) value+=grid[i][j1];
                else value+=grid[i][j1]+grid[i][j2];
                value+=solve(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,grid,dp);
    }





int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }




int solve(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || j>=matrix.size()) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,matrix,dp);
        int ld=solve(i-1,j-1,matrix,dp);
        int rd=solve(i-1,j+1,matrix,dp);
        return dp[i][j]=matrix[i][j]+min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,solve(n-1,i,matrix,dp));
        // }
        // return ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) dp[i][j]=matrix[i][j];
                else{
                    int up=1e9;
                    int ld=1e9;
                    int rd=1e9;
                    up=dp[i-1][j];
                    if(j>0) ld=dp[i-1][j-1];
                    if(j<n-1) rd=dp[i-1][j+1];
                    dp[i][j]=matrix[i][j]+min(up,min(ld,rd));
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }



int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        // return solve(n-1,m-1,grid,dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else{
                    int left=1e9;
                    int up=1e9;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }



// is there a subset which add up to target
f(ind ,target){
    if(target==0) return true;
    if(ind==0) return (a[0]==target);
    bool notTake=f(ind-1,target);
    bool take=false;
    if(a[ind]<=target) take=f(ind-1,target-a[i]);
    return take||notTake;
}



int solve(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(solve(i+1,j,triangle,dp),solve(i+1,j+1,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        // return solve(0,0,triangle,dp);
        int n=triangle.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                if(i==n-1) dp[i][j]=triangle[i][j];
                else{
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }





int solve(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,dp);
        int left=solve(i,j-1,dp);
        return dp[i][j]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,dp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
                
            }
        }
        return dp[m-1][n-1];
    }



int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        if(obstacleGrid[0][0]==1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    int left=0;
                    int up=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }




int solve(int index,int w,int wt[],int val[],vector<vector<int>> &dp){
        if(index==0){
            if(wt[index]<=w) return val[index];
            else return 0;
        }
        if(dp[index][w]!=-1) return dp[index][w];
        int notTake=solve(index-1,w,wt,val,dp);
        int take=INT_MIN;
        if(w>=wt[index]) take=val[index]+solve(index-1,w-wt[index],wt,val,dp);
        return dp[index][w]=max(take,notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,0));
    //   return solve(n-1,W,wt,val,dp);
        for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
        for(int i=1;i<n;i++){
            for(int j=1;j<=W;j++){
                int notTake=dp[i-1][j];
                int take=INT_MIN;
                if(j>=wt[i]) take=val[i]+dp[i-1][j-wt[i]];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[n-1][W];
    }






int solve(int index,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(index==0){
            if(amount%coins[index]==0) return amount/coins[index];
            else return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=solve(index-1,amount,coins,dp);
        int take=1e9;
        if(amount>=coins[index]) take=1+solve(index,amount-coins[index],coins,dp);
        return dp[index][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // int ans=solve(n-1,amount,coins,dp);
        // if(ans==1e9) return -1;
        // else return ans;
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notTake=dp[i-1][j];
                int take=1e9;
                if(j>=coins[i]) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,notTake);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }




int solve(int index,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(index==0){
            if(amount%coins[index]==0) return 1;
            else return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=solve(index-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[index]) take=solve(index,amount-coins[index],coins,dp);
        return dp[index][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // return solve(n-1,amount,coins,dp);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake=dp[i-1][j];
                int take=0;
                if(j>=coins[i]) take=dp[i][j-coins[i]];
                dp[i][j]=take+notTake;
            }
        }
        return dp[n-1][amount];
    }




int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j];
                }
                else{
                    if(matrix[i][j]==0){
                        dp[i][j]=0;
                    }
                    else{
                        dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    }
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }




int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}

int countPartitions(int d, vector<int>& arr){
    int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);
}



int numDecodings(string s) {
        vector<int> dp(s.length()+1);
        if(s[0]=='0') return 0;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=s.length();i++){
            if(s[i-1]>='1' && s[i-1]<='9') dp[i]=dp[i-1];
            if(s[i-2]=='1') dp[i]+=dp[i-2];
            else if(s[i-2]=='2' && (s[i-1]>='0' && s[i-1]<='6')) dp[i]+=dp[i-2];
        }
        return dp[s.length()];
    }




int solve(int index1,int index2,string &text1,string &text2,vector<vector<int>> &dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(text1[index1]==text2[index2]) return dp[index1][index2]=1+solve(index1-1,index2-1,text1,text2,dp);
        else{
            return dp[index1][index2]=max(solve(index1-1,index2,text1,text2,dp),solve(index1,index2-1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,text1,text2,dp);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];                              
    }




int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j]-'0';
                }
                else{
                    if(matrix[i][j]=='0'){
                        dp[i][j]=0;
                    }
                    else{
                        dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    }
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }




// last row stores is using all elements we can make a sum or not
    int minDifference(int arr[], int n){ 
        int sum=accumulate(arr,arr+n,0);
        vector<vector<bool>> dp(n,vector<bool>(sum,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(j>=arr[i]) take=dp[i-1][j-arr[i]];
                dp[i][j]=take||notTake;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=sum;i++){
            if(dp[n-1][i]==true){
                int s1=i;
                int s2=sum-s1;
                ans=min(ans,abs(s1-s2));
            }
        }
        return ans;
    } 




bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum=sum/2;
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum+1,false));
        for(int i=0;i<=sum;i++) dp[0][i]=false;
        for(int i=0;i<nums.size();i++) dp[i][0]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(j>=nums[i]) take=dp[i-1][j-nums[i]];
                dp[i][j]=take||notTake;
            }
        }
        return dp[nums.size()-1][sum];
    }




int solve(int index,int sum,int arr[],vector<vector<int>> &dp){
        if(index<0){
            if(sum==0) return 1;
            else return 0;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        int notPick=solve(index-1,sum,arr,dp);
        int pick=0;
        if(arr[index]<=sum) pick=solve(index-1,sum-arr[index],arr,dp);
        return dp[index][sum]=(pick+notPick)%1000000007;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
        // for(int i=0;i<n;i++) dp[i][0]=1;
        // if(arr[0]<=sum) dp[0][arr[0]]=1;
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=sum;j++){
        //         int notPick=dp[i-1][j];
        //         int pick=0;
        //         if(j>=arr[i]) pick=dp[i-1][j-arr[i]];
        //         dp[i][j]=pick+notPick;
        //     }
        // }
        // return dp[n-1][sum];
    }




// try to pick lengths and sum them up to make the given n 
    // unbounded knapsack
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,0));
        for(int i=0;i<=W;i++) dp[0][i]=(i/wt[0])*val[0];
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int notTake=dp[i-1][j];
                int take=INT_MIN;
                if(j>=wt[i]) take=val[i]+dp[i][j-wt[i]];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[N-1][W];
    }
    int cutRod(int price[], int n) {
        int wt[n];
        for(int i=0;i<n;i++) wt[i]=i+1;
        return knapSack(n,n,price,wt);
    }




// two subset with difference target 
    // s1-s2=target
    // totalSum-s2-s2=target
    int solve(int index,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(index<0){
            if(target==0) return 1;
            else return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake=solve(index-1,target,nums,dp);
        int take=0;
        if(target>=nums[index]) take=solve(index-1,target-nums[index],nums,dp);
        return dp[index][target]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(target>sum) return 0;
        if((sum-target)%2==1) return 0;
        vector<vector<int>> dp(n,vector<int> ((sum-target)/2+1,-1));
        return solve(n-1,(sum-target)/2,nums,dp);
    }




int solve(int index,int w,int wt[],int val[],vector<vector<int>> &dp){
        if(index==0){
            return (w/wt[index])*val[index];
        }
        if(dp[index][w]!=-1) return dp[index][w];
        int notTake=solve(index-1,w,wt,val,dp);
        int take=INT_MIN;
        if(w>=wt[index]) take=val[index]+solve(index,w-wt[index],wt,val,dp);
        return dp[index][w]=max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,0));
        // return solve(N-1,W,wt,val,dp);
        for(int i=0;i<=W;i++) dp[0][i]=(i/wt[0])*val[0];
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int notTake=dp[i-1][j];
                int take=INT_MIN;
                if(j>=wt[i]) take=val[i]+dp[i][j-wt[i]];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[N-1][W];
    }



int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            ans=max(ans,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return ans;
    }




// we are currently standing on a index we can buy are allowed to buy , or do nothing elsse sell or do nothing
    int solve(int index,bool buy,vector<int>& prices,vector<vector<int>> &dp){
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            return dp[index][buy]=max(-prices[index]+solve(index+1,0,prices,dp),solve(index+1,1,prices,dp));
        }
        else{
            return dp[index][buy]=max(prices[index]+solve(index+1,1,prices,dp),solve(index+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // // return solve(0,1,prices,dp);
        // dp[n][0]=dp[n][1]=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         if(j) dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
        //         else dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
        //     }
        // }
        // return dp[0][1];
        vector<int> ahead(2,0),cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j) cur[j]=max(-prices[i]+ahead[0],ahead[1]);
                else cur[j]=max(prices[i]+ahead[1],ahead[0]);
            }
            ahead=cur;
        }
        return cur[1];
    }



// or n*4 (Buy sell buy sell)
    int solve(int index,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(index==prices.size()) return 0;
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        if(buy){
            return dp[index][buy][cap]=max(-prices[index]+solve(index+1,0,cap,prices,dp),solve(index+1,1,cap,prices,dp));
        }
        else{
            return dp[index][buy][cap]=max(+prices[index]+solve(index+1,1,cap-1,prices,dp),solve(index+1,0,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(0,1,2,prices,dp);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j) dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    else dp[i][j][k]=max(+prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                }
            }
        }
        return dp[0][1][2];
    }




int solve(int i,int tranNo,vector<int>& prices,int n,int k,vector<vector<int>> &dp){
        if(i==n || tranNo==2*k) return 0;
        if(dp[i][tranNo]!=-1) return dp[i][tranNo];
        if(tranNo%2==0) return dp[i][tranNo]=max(-prices[i]+solve(i+1,tranNo+1,prices,n,k,dp),solve(i+1,tranNo,prices,n,k,dp));
        else return dp[i][tranNo]=max(+prices[i]+solve(i+1,tranNo+1,prices,n,k,dp),solve(i+1,tranNo,prices,n,k,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2*k,-1));
        // return solve(0,0,prices,n,k,dp);
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j%2==0) dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                else dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
        
        // int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         for(int l=1;l<=k;l++){
        //             if(j) dp[i][j][l]=max(-prices[i]+dp[i+1][0][l],dp[i+1][1][l]);
        //             else dp[i][j][l]=max(+prices[i]+dp[i+1][1][l-1],dp[i+1][0][l]);
        //         }
        //     }
        // }
        // return dp[0][1][k];
    }





int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp){
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            return dp[index][buy]=max(-prices[index]+solve(index+1,0,prices,dp),solve(index+1,1,prices,dp));
        }
        else  return dp[index][buy]=max(+prices[index]+solve(index+2,1,prices,dp),solve(index+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        // return solve(0,1,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j) dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }





int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> ahead(2,0),cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j) cur[j]=max(-prices[i]-fee+ahead[0],ahead[1]);
                else cur[j]=max(prices[i]+ahead[1],ahead[0]);
            }
            ahead=cur;
        }
        return cur[1];
    }




int solve(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=solve(i-1,j-1,word1,word2,dp);
        return dp[i][j]=min(1+solve(i-1,j,word1,word2,dp),1+solve(i,j-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }




int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=solve(i-1,j,s,t,dp)+solve(i-1,j-1,s,t,dp);
        else return dp[i][j]=solve(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,s,t,dp);
        vector<vector<double >> dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }




int solve(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return solve(i-1,j-1,word1,word2,dp);
        int insertion=1+solve(i,j-1,word1,word2,dp);
        int deletion=1+solve(i-1,j,word1,word2,dp);
        int replace=1+solve(i-1,j-1,word1,word2,dp);
        return dp[i][j]=min(insertion,min(deletion,replace));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,word1,word2,dp);
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insertion=1+dp[i][j-1];
                    int deletion=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(insertion,min(deletion,replace));
                }
            }
        }
        return dp[n][m];
    }




int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][i]=0;
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }




int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];                              
    }
    int longestPalindromeSubseq(string s) {
        string temp=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,temp);
    }





// length - lcs
    // keeping the longest portion intact
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];                              
    }
    int minInsertions(string s) {
        string temp=s;
        reverse(s.begin(),s.end());
        return s.length()-longestCommonSubsequence(temp,s);
    }




    // deletions=n-lcs
    // insertions=m-lcs
    // total operations=n+m-2*lcs
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];                              
    }
    int minOperations(string str1, string str2) 
    { 
        return str1.length()+str2.length()-2*longestCommonSubsequence(str1,str2);
    }





void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int len = dp[n][m];
  int i = n;
  int j = m;

  int index = len - 1;
  string str = "";
  for (int k = 1; k <= len; k++) {
    str += "$"; // dummy string
  }

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } else if (s1[i - 1] > s2[j - 1]) {
      i--;
    } else j--;
  }
  cout << str;
}






// n+m-lcs
    // but we need to find the string
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }





int solve(int i,int j,string &p,string &s,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int k=0;k<=i;k++) if(p[k]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[i]==s[i] || p[i]=='?') return dp[i][j]=solve(i-1,j-1,p,s,dp);
        else if(p[i]=='*') return dp[i][j]=solve(i-1,j,p,s,dp)||solve(i,j-1,p,s,dp);
        return false;
    }
    bool isMatch(string s, string p) {
        int n=p.length();
        int m=s.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,p,s,dp);
    }





// dp will be of i , j , what we want (true or false) and it will store no of ways
    int solve(int i,int j,bool isTrue,string &s,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways=0;
        for(int ind=i+1;ind<j;ind+=2){
            int lT=solve(i,ind-1,1,s,dp);
            int lF=solve(i,ind-1,0,s,dp);
            int rT=solve(ind+1,j,1,s,dp);
            int rF=solve(ind+1,j,0,s,dp);
            if(s[ind]=='&'){
                if(isTrue) ways+=(rT*lT)%1003;
                else ways+=(lF*rF+lF*rT+lT*rF)%1003;
            }
            else if(s[ind]=='|'){
                if(isTrue) ways+=(lT*rT+lF*rT+lT*rF)%1003;
                else ways+=(lF*rF)%1003;
            }
            else{
                if(isTrue) ways+=(lT*rF+lF*rT)%1003;
                else ways+=(lF*rF+lT*rT)%1003;
            }
        }
        return dp[i][j][isTrue]=ways%1003;
    }
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N,vector<vector<int>> (N,vector<int>(2,-1)));
        return solve(0,N-1,1,S,dp);
    }




// think when balloon is left
    int solve(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1]+solve(k+1,j,nums,dp)+solve(i,k-1,nums,dp);
            maxi=max(maxi,coins);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return solve(1,n,nums,dp);
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int coins=nums[i-1]*nums[k]*nums[j+1]+dp[k+1][j]+dp[i][k-1];
                    maxi=max(maxi,coins);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }




vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n);
        sort(nums.begin(),nums.end());
        int maxi=1;
        int lastIndex=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }




int lengthOfLIS(vector<int>& nums) {
        // vector<int> dp(nums.size(),1);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
        vector<int> temp;// temporaty array is not the list , we are just storing elements
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }





int LongestBitonicSequence(vector<int>nums)
    {
        int n=nums.size();
        vector<int> dp1(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp1[i]<dp1[j]+1){
                    dp1[i]=dp1[j]+1;
                }
            }
        }
        
        vector<int> dp2(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j] && dp2[i]<dp2[j]+1){
                    dp2[i]=dp2[j]+1;
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }




bool checkPossible(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int i=0;
        int j=0;
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else i++;
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }
    static bool cmp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=1;
        sort(words.begin(),words.end(),cmp);// sorting it acc to lenght , we want a sequence not a subsequence
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkPossible(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }




// tc=> n*n*n
    // sc=> n*n 
    int solve(int i,int j,int arr[],vector<vector<int>> &dp){
        if(i==j) return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        // return solve(1,N-1,arr,dp);
        for(int i=0;i<N;i++) dp[i][i]=0;
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
    }




int solve(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
        // return solve(1,c,cuts,dp);
        vector<vector<int>> dp(c+2,vector<int> (c+2,0));
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }





int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),count(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j] && dp[i]==dp[j]+1){
                    count[i]+=count[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i]) ans+=count[i];
        }
        return ans;
    }




bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int n,string &s,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+solve(j+1,n,s,dp);
                mini=min(mini,cost);
            } 
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        // vector<int> dp(n,-1);
        // return solve(0,n,s,dp)-1; // -1 as it is doing partion at the end also
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost=1+dp[j+1];
                    mini=min(mini,cost);
                } 
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }




int solve(int i,vector<int> &arr,int k,int n,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+solve(j+1,arr,k,n,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[i]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,n,dp);
    }





// we will store in temp , the score we will get after deleting that element
    int deleteAndEarn(vector<int>& nums) {
        vector<int> temp(1e4+1,0);
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]+=nums[i];
        }
        int prev=temp[0];
        int prev2=0;
        for(int i=1;i<temp.size();i++){
            int cur=max(prev,prev2+temp[i]);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }



int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int maxi=nums[0];
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(maxi,mini);
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }




int findPar(int u,vector<int> &parent){
        if(u==parent[u]) return u;
        return parent[u]=findPar(parent[u],parent);
    }
    void Union(int u,int v,vector<int> &parent,vector<int> &rank){
        u=findPar(u,parent);
        v=findPar(v,parent);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        vector<int> rank(n+1,0);
        for(auto it:edges){
            if(findPar(it[0],parent)!=findPar(it[1],parent)){
                Union(it[0],it[1],parent,rank);
            }
            else return it;
        }
        vector<int> ans;
        return ans;
    }




// giving tle
// at every floor there are two possibilities that the egg can break or not
    int solve(int f,int e,vector<vector<int>> &dp){
        if(f==1 || f==0) return f;
        if(e==1) return f;
        if(dp[f][e]!=-1) return dp[f][e];
        int ans=INT_MAX;
        for(int i=1;i<=f;i++){
            int moves=1+max(solve(i-1,e-1,dp),solve(f-i,e,dp));
            ans=min(ans,moves);
        }
        return dp[f][e]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }




int trap(vector<int>& a) {
        int l=0;
        int r=a.size()-1;
        int ans=0;
        int leftMax=0;
        int rightMax=0;
        while(l<=r){
            if(a[l]<=a[r]){
                if(a[l]<=leftMax) ans+=leftMax-a[l];
                else leftMax=a[l];
                l++;
            }
            else{
                if(a[r]<=rightMax) ans+=rightMax-a[r];
                else rightMax=a[r];
                r--;
            }
        }
        return ans;
    }





int solve(int n,vector<int> &dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve(i,dp)*solve(n-i-1,dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }






int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance=0;
        int start=0;
        int deficit=0;
        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficit+=balance;
                balance=0;
                start=i+1;
            }
        }
        return balance+deficit>=0?start:-1;
    }



// left and right will be at zero, if valid move right , if not move left till it is valid
    // valid means we can make the substring equal
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int maxCount=0;
        int ans=0;
        unordered_map<char,int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            maxCount=max(maxCount,mp[s[j]]);
            while(((j-i+1)-maxCount)>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }





// run dfs
void dfs(int node,unordered_map<int,vector<int>> &mp,set<int> &vis,vector<int> &ans){
        if(vis.find(node)!=vis.end()) return ;
        ans.push_back(node);
        vis.insert(node);
        for(auto it:mp[node]){
            dfs(it,mp,vis,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        for(auto it:adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int start;
        for(auto it:mp){
            if(it.second.size()==1){
                start=it.first;
                break;
            }
        }
        set<int> vis;
        vector<int> ans;
        dfs(start,mp,vis,ans);
        
        return ans;
    }




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





// number of beutiful arrangements (perm[i] is divisible by i or i is divisible by perm[i])
int solve(int index,vector<int> &v){
        if(index==v.size()) return 1;
        int ans=0;
        for(int i=index;i<v.size();i++){
            if(v[i]%(index+1)==0 || (index+1)%v[i]==0){
                swap(v[index],v[i]);
                ans+=solve(index+1,v);
                swap(v[index],v[i]);
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=i+1;
        return solve(0,v);
    }




// generate all possible combinations of k numbers
void solve(int n,int k,vector<vector<int>> &ans,vector<int> &ds){
        if(k==0){
            ans.push_back(ds);
            return ;
        }
        if(n==0) return ;
        
        ds.push_back(n);
        solve(n-1,k-1,ans,ds);
        ds.pop_back();
        
        solve(n-1,k,ans,ds);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(n,k,ans,ds);
        return ans;
    }



// cannot pick a element more than once for the same position
    void combinationSum(int ind,int target,vector<int>& candidates,vector<vector<int>> &ans,vector<int> &ds){

        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        // for the same index we will not element of same value
        // we are one by one pickinig our first element 
        // then second element
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break; // if not able to pick this , can't pick ahead (as sorted)
            ds.push_back(candidates[i]);
            combinationSum(i+1,target-candidates[i],candidates,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // in combination sum 2, combinations should not repeat
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        // we will put subsequences
        combinationSum(0,target,candidates,ans,ds);
        return ans;
    }




bool issafe(int node,int color[],bool graph[101][101],int n,int i){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==i) return false;
    }
    return true;
}
bool solve(int node,bool graph[101][101],int m,int n,int color[]){
    if(node==n) return true;
    for(int i=1;i<=m;i++){
        if(issafe(node,color,graph,n,i)){
            color[node]=i;
            if(solve(node+1,graph,m,n,color)) return true;
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V]={0};
    return solve(0,graph,m,V,color);
}




// if only one of the child is null then , that node is not leaf
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        return (left==0||right==0)?left+right+1:min(left,right)+1;
    }



// stack will store char and needed time
int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>> st;
        int ans=0;
        st.push({colors[0],neededTime[0]});
        for(int i=1;i<colors.size();i++){
            if(colors[i]==st.top().first){
                int prev=st.top().second;
                st.pop();
                int cur=neededTime[i];
                ans+=min(cur,prev);
                if(prev<cur){
                    st.push({colors[i],cur});
                }
                else st.push({colors[i],prev});
            }
            else st.push({colors[i],neededTime[i]});
        }
        return ans;
    }



bool isValid(int row,int col,vector<string> &board,int n){
        int i=row;
        while(i>=0){
            if(board[i][col]=='Q') return false;
            i--;
        }
        i=row;
        int j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i>=0 && j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> &board,int n,int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(row,i,board,n)){
                board[row][i]='Q';
                solve(ans,board,n,row+1);
                board[row][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(ans,board,n,0);
        return ans;
    }





bool isPalindrome(int start,int end,string &s){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(int index,string &s,vector<vector<string>> &ans,vector<string> &path){
        if(index==s.length()){
            ans.push_back(path);
            return ;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,ans,path);
        return ans;
    }




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




// ***********************
vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n+1,vector<int> (m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]+matrix[i][j]-dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }



void func(int index,vector<vector<int>> &ans,vector<int> &ds,vector<int>& nums){
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            func(i+1,ans,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        func(0,ans,ds,nums);
        return ans;
    }





bool isValid(int row,int col,char check,vector<vector<char>> &boards){
        for(int i=0;i<9;i++){
            if(boards[row][i]==check) return false;
            if(boards[i][col]==check) return false;
            if(boards[3*(row/3)+i/3][3*(col/3)+i%3]==check) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&boards){
        for(int i=0;i<boards.size();i++){
            for(int j=0;j<boards[0].size();j++){
                if(boards[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(i,j,c,boards)){
                            boards[i][j]=c;
                            if(solve(boards)==true){
                                return true;
                            }
                            else{
                                boards[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& boards) {
        bool temp=solve(boards);
    }






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




int dfs(int i,int j,int zero,vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1) return 0;
        if(grid[i][j]==2) return zero==-1?1:0;
        int totalPath=0;
        grid[i][j]=-1;
        zero--;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            totalPath+=dfs(i+dx[k],j+dy[k],zero,grid);
        }
        grid[i][j]=0;
        zero++;
        return totalPath;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x,y;
        int zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) zero++;
                else if(grid[i][j]==1) x=i,y=j;
            }
        }
        return dfs(x,y,zero,grid);
    }





void solve(int index,string &s,unordered_map<string,int> mp,vector<vector<string>> &ans,vector<string> &ds){
        if(index==s.length()) {
            ans.push_back(ds);
            return ;
        }
        string temp;
        for(int i=index;i<s.length();i++){
            temp+=s[i];
            if(mp.find(temp)!=mp.end()){
                ds.push_back(temp);
                solve(i+1,s,mp,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> ans;
        vector<string> ds;
        unordered_map<string,int> mp;
        for(auto it:wordDict) mp[it]++;
        solve(0,s,mp,ans,ds);
        vector<string> finalAns;
        for(auto it:ans){
            string temp="";
            for(auto cur:it){
                if(temp.length()==0) temp+=cur;
                else{
                    temp+=" ";
                    temp+=cur;
                }
            }
            finalAns.push_back(temp);
        }
        return finalAns;
    }





vector<int> diffWaysToCompute(string s) {
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*' || s[i]=='+' || s[i]=='-'){
                vector<int> left=diffWaysToCompute(s.substr(0,i));
                vector<int> right=diffWaysToCompute(s.substr(i+1));
                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){
                        if(s[i]=='+') ans.push_back(left[j]+right[k]);
                        else if(s[i]=='*') ans.push_back(left[j]*right[k]);
                        else ans.push_back(left[j]-right[k]);
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(stoi(s));
        return ans;
    }





int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        dp[n][m]=1;
        dp[n-1][m]=1;
        dp[n][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int minHealth=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                dp[i][j]=(minHealth<=0)?1:minHealth;
            }
        }
        return dp[0][0];
    }




string solve(TreeNode* root,unordered_map<string,vector<TreeNode*>> &mp){
        if(root==NULL) return "";
        string s="";
        s+='(';
        s+=solve(root->left,mp);
        s+=to_string(root->val);
        s+=solve(root->right,mp);
        s+=')';
        mp[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> mp;
        solve(root,mp);
        vector<TreeNode*> ans;
        for(auto it:mp){
            if(it.second.size()>=2){
                ans.push_back(it.second[0]);
            }
        }
        return ans;
    }




int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int endTime=intervals[0][1];
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<endTime){
                ans++;
                endTime=min(endTime,intervals[i][1]);
            }
            else{
                endTime=intervals[i][1];
            }
        }
        return ans;
    }





// for all divisors
bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                string temp=s.substr(0,i);
                string tempString="";
                for(int j=0;j<(n/i);j++){
                    tempString+=temp;
                }
                if(tempString==s) return true;
            }
        }
        return false;
    }




// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans="";
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL) ans+="#,";
            else ans+=(to_string(cur->val)+',');
            if(cur!=NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                cur->left=NULL;
            }
            else{
                TreeNode* l=new TreeNode(stoi(str));
                cur->left=l;
                q.push(l);
            }
            getline(s,str,',');
            if(str=="#"){
                cur->right=NULL;
            }
            else{
                TreeNode* r=new TreeNode(stoi(str));
                cur->right=r;
                q.push(r);
            }
        }
        return root;
    }





// tc-> (logn)^2
// for complete tree , no of node => 2^n -1
    int leftHeight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    int rightHeight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==0) return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }



// tarjan's algo
// time of insertion (tin), lowest time(low)
void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<vector<int>> &adj,vector<vector<int>> &ans){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it:adj[node]){
            if(parent==it) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,timer,adj,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({node,it});
                }
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        int timer=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,timer,adj,ans);
            }
        }
        return ans;
    }





// design a text editor
string left="";
    string right="";
    TextEditor() {
        
    }
    
    void addText(string text) {
        left+=text;
    }
    
    int deleteText(int k) {
        int deleted=0;
        while(k>0 && left.size()!=0){
            left.pop_back();
            k--;
            deleted++;
        }
        return deleted;
    }
    
    string cursorLeft(int k) {
        while(k>0 && left.size()!=0){
            right.push_back(left.back());
            left.pop_back();
            k--;
        }
        if(left.length()<10) return left;
        else return left.substr(left.size()-10);
    }
    
    string cursorRight(int k) {
        while(k>0 && right.size()!=0){
            left.push_back(right.back());
            right.pop_back();
            k--;
        }
        if(left.length()<10) return left;
        else return left.substr(left.size()-10);
    }




string largestTimeFromDigits(vector<int>& a) {
        sort(a.begin(),a.end(),greater<int>());
        do{
            if((a[0]==2 && a[1]<=3 && a[2]<=5 && a[3]<=9) || (a[0]<=1 && a[1]<=9 && a[2]<=5 && a[3]<=9)){
                string ans="";
                ans+=to_string(a[0])+to_string(a[1])+":"+to_string(a[2])+to_string(a[3]);
                return ans;
                break;
            }
        }while(prev_permutation(a.begin(),a.end()));
        return "";
    }




// from a given position check , what is the minimum that we can go from here
// minimum number of squares to make n
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            for(int j=1;j*j<=i;j++){
                mini=min(mini,dp[i-j*j]);
            }
            dp[i]=mini+1;
        }
        return dp[n];
    }




// Sieve
// tc -> n(log(logn))
vector<bool> isPrime(n,1);
isPrime[0]=isPrime[1]=false;
for(int i=2;i<n;i++){
    if(isPrime[i]==true){
        for(int j=2*i;j<n;j+=i){
            isPrime[j]=false;
        }
    }
}




long long int solve(int i,int j,string &s,vector<vector<long long int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]= (1+solve(i+1,j,s,dp)+solve(i,j-1,s,dp)+1000000007)%(1000000007);
        }
        else{
            return dp[i][j]= (solve(i+1,j,s,dp)+solve(i,j-1,s,dp)-solve(i+1,j-1,s,dp)+1000000007)%(1000000007);
        }
    }
    long long int  countPS(string str)
    {
       int i=0;
       int j=str.length()-1;
       vector<vector<long long int >> dp(str.length(),vector<long long int>(str.length(),-1));
       return solve(0,j,str,dp);
    }





int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i ;
        for( i=0;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            int dif=heights[i+1]-heights[i];
            if(bricks>=dif){
                pq.push(dif);
                bricks-=dif;
            }
            else if(ladders>0){
                if(!pq.empty()){
                    if(pq.top()>dif){
                        int maxBricksUsed=pq.top();
                        pq.pop();
                        bricks+=maxBricksUsed-dif;
                        pq.push(dif);
                    }
                }
                ladders--;
            }
            else break;
        }
        return i;
    }





// if cell becoming dead replace with -1
    // if cell becoming live replace with 2
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dx[]={0,0,1,1,1,-1,-1,-1};
        int dy[]={1,-1,1,-1,0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int countOne=0;
                for(int k=0;k<8;k++){
                    int cx=i+dx[k];
                    int cy=j+dy[k];
                    if(cx<0 || cy<0 || cx>=n || cy>=m) continue;
                    if(abs(board[cx][cy])==1) countOne++;
                }
                if(board[i][j]==0){
                    if(countOne==3){
                        board[i][j]=2;
                    }
                }
                else if(board[i][j]==1){
                    if(countOne<2 || countOne>3){
                        board[i][j]=-1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-1) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
    }




 // min heap -> nlogk
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }



// sorting algo
// selection sort -> place smallest element in correct position
    // sc=> 1 , tc=> n^2
    // best case => n^2 , worst case => n^2
    // usecase => small array size
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int minIndex=i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[minIndex]){
                    minIndex=j;
                }
            }
            swap(nums[i],nums[minIndex]);
        }
        return nums;
    }

// bubble sort
// compare adjacents
    // largest element will be placed
    // use case
    // tc=> n^2 , sc=> 1
    // can be further optimized , if number of swaps is zero than the array is sorted
    vector<int> sortArray(vector<int>& a) {
        int n=a.size();
        bool swapped=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    swapped=true;
                }
            }
            if(swapped==false) break;
        }
        return a;
    }

// insertion sort
// adaptible
    // stable algo
    // better in partially sorted 
    // tc=> n^2  , sc=> 1
    // best cast => n , worst case=> n^2
    vector<int> sortArray(vector<int>& a) {
        int n=a.size();
        for(int i=1;i<n;i++){
            int temp=a[i];
            int j=i-1;
            for(j;j>=0;j--){
                if(a[j]>temp){
                    a[j+1]=a[j];
                }
                else{
                    break;
                }
            }
            a[j+1]=temp;
        }
        return a;
    }





vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            counts[nums[i]]++;
        }
        for(auto it:counts){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }





vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<points.size();i++){
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
        }
        vector<vector<int>> ans;
        while(k>0 && !pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            ans.push_back({x,y});
            k--;
        }
        return ans;
    }





// push all stations before current , in max heap
    // take if distance is less than target
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0;
        int cur=startFuel;
        int ans=0;
        priority_queue<int> pq;
        while(cur<target){
            while(i<stations.size() && stations[i][0]<=cur) pq.push(stations[i++][1]);
            if(pq.empty()) return -1;
            cur+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }





int solve(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>j) return 1;
        if(dp[i][j]!=-1) return dp[i][j]; 
        return dp[i][j]= s[i]==s[j]?solve(i+1,j-1,s,dp):0;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
        // vector<vector<int>> dp(n,(vector<int>(n,-1)));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         ans+=solve(i,j,s,dp);
        //     }
        // }
        // return ans;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int dif=0;dif<n;dif++){ // length of string -1 i.e. dif between i and j
            for(int i=0,j=dif;j<n;i++,j++){
                if(dif==0) dp[i][j]=true;
                else if(dif==1){
                    dp[i][j]= (s[i]==s[j]);
                }
                else{
                    if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                    else dp[i][j]=false;
                }
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }






string reorganizeString(string s) {
        map<int,int> counts;
        for(auto it:s) counts[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:counts){
            pq.push({it.second,it.first});
        }
        pair<int,int> top1,top2;
        string ans="";
        while(!pq.empty()){
            top1=pq.top();
            pq.pop();
            ans+=(char)top1.second;
            if(!pq.empty()){
                top2=pq.top();
                pq.pop();
                ans+=(char)top2.second;
                if(top2.first>1) pq.push({top2.first-1,top2.second});
            }
            if(top1.first>1) pq.push({top1.first-1,top1.second});     
        }
        for(int i=0;i<ans.length()-1;i++){
            if(ans[i]==ans[i+1]) return "";
        }
        return ans;
    }





// storing in dq in decreasing order
    // storing index in dq
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();// remove out of bound element
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();// removing all element less than i
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);// after we have checked for 1st subarray of size k
        }
        return ans;
    }



// binary search on time , for each time run dfs
    bool dfs(int x,int y,int t,vector<vector<int>> &grid,vector<vector<int>> &vis){
        if(grid[x][y]>t) return false;
        if(x==grid.size()-1 && y==grid.size()-1) return true;
        vis[x][y]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(cx<0 || cy<0 || cx>=grid.size() || cy>=grid.size() || vis[cx][cy]) continue;
            if(dfs(cx,cy,t,grid,vis)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int low=0;
        int high=50*50;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            vector<vector<int>> vis(n,vector<int>(n,0));
            if(dfs(0,0,mid,grid,vis)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }






vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int l=i+1;
                int h=n-1;
                int sum=0-nums[i];
                while(l<h){
                    if(nums[l]+nums[h]==sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);
                        l++;
                        h--;
                        while(l<h && nums[l]==nums[l-1]) l++;
                        while(l<h && nums[h]==nums[h+1]) h--;
                    }
                    else if(nums[l]+nums[h]>sum) h--;
                    else l++;
                }
            }
        }
        return ans;
    }




vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j=i+1;j<n-2;j++){
                    if(j==i+1 || nums[j]!=nums[j-1]){
                        cout<<j<<endl;
                        int l=j+1;
                        int h=n-1;
                        int sum=target-nums[i]-nums[j];
                        while(l<h){
                            if(nums[l]+nums[h]==sum){
                                ans.push_back({nums[i],nums[j],nums[l],nums[h]});
                                l++;
                                h--;
                                while(l<h && nums[l]==nums[l-1]) l++;
                                while(l<h && nums[h]==nums[h+1]) h--;
                            }
                            else if(nums[l]+nums[h]>sum) h--;
                            else l++;
                        }
                    }
                }
            }
        }
        return ans;
    }




// binary tree to bst
// find inorder , sort it then and traverse in inorder and change the values




void solve(int s,int h,int d,int n,long long &count){
    if(n==1){
        cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
        count++;
        return ;
    }
    solve(s,d,h,n-1,count);
    cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
    count++;
    solve(h,s,d,n-1,count);
}
long long toh(int N, int from, int to, int aux) {
    long long count=0;
    solve(from,aux,to,N,count);
    return count;
}




// find nth ugly number
// take three pointers
int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int p1=0;
        int p2=0;
        int p3=0;
        for(int i=1;i<n;i++){
            int twomultiple=dp[p1]*2;
            int threemultiple=dp[p2]*3;
            int fivemultiple=dp[p3]*5;
            dp[i]=min(twomultiple,min(threemultiple,fivemultiple));
            if(dp[i]==twomultiple) p1++;
            if(dp[i]==threemultiple) p2++;
            if(dp[i]==fivemultiple) p3++;
        }
        return dp[n-1];
    }






// (a+b)%m =
// (a-b)%m =
// (a*b)%m =
// (a/b)%m = (a%m)*((b^-1)%m)%m
// if b is very large
// eulers=> a^b % m = a^(b%phi(m)) %m
// etf=phi(n) is number's less tha n which are co prime with n (coprime => gcd => 1), n*prod(1-1/p) => p is all prime factors
// for prime number eft=n-1

// for prime m
// a^b %m=a^(b%(m-1)) %m





int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
        int ans=0;
        int end=s.length();
        while(!st.empty()){
            int start=st.top();
            st.pop();
            ans=max(ans,end-start-1);
            end=start;
        }
        return max(ans,end);
    }





// only 6 cells are changing => 2^6=64 combinations , means pattern will repeat
vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        set<vector<int>> st;
        int size=0;
        for(int i=0;i<n;i++){ // this will not run n time , it will break when , we will find the pattern
            vector<int> temp(8,0);
            for(int i=1;i<7;i++){
                temp[i]= (cells[i-1]==cells[i+1]);
            }
            if(st.find(temp)!=st.end()) break;
            cells=temp;
            st.insert(temp);
            size++;
        }
        for(auto it:cells) cout<<it<<" ";
        n=n%size;
        for(int i=0;i<n;i++){
            vector<int> temp(8,0);
            for(int j=1;j<7;j++){
                temp[j]= cells[j-1]==cells[j+1];
            }
            cells=temp;
        }
        return cells;
    }





bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec2[0]<rec1[2] && rec2[2]>rec1[0] && rec2[1]<rec1[3] && rec2[3]>rec1[1];
    }




// **********************
// dfs1 is to mark the count and calculate the answer for root node
// dfs is to re-root the roots to calculate the anwer for all nodes
// count is no of nodes in its substree
void dfs1(int i,int parent,vector<int> &count,vector<int> &res,vector<vector<int>> &v){
        for(auto it:v[i]){
            if(it==parent) continue;
            dfs1(it,i,count,res,v);
            count[i]+=count[it];
            res[i]+=res[it]+count[it];
        }
        count[i]++;
    }
    void dfs(int i,int parent,int n,vector<int> &count,vector<int> &res,vector<vector<int>> &v){
        for(auto it:v[i]){
            if(it==parent) continue;
            res[it]=res[i]-count[it]+n-count[it];
            dfs(it,i,n,count,res,v);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> count(n,0);
        vector<int> res(n,0);
        vector<vector<int>> v(n);
        for(auto it:edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        dfs1(0,-1,count,res,v);
        dfs(0,-1,n,count,res,v);
        return res;
    }




void solve(int i,vector<int> &v,vector<int> &cookies,int k,int &ans){
        if(i==cookies.size()){
            ans=min(ans,*max_element(v.begin(),v.end()));
            return ;
        }
        for(int j=0;j<k;j++){
            v[j]+=cookies[i];
            solve(i+1,v,cookies,k,ans);
            v[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        vector<int> v(cookies.size(),0);
        solve(0,v,cookies,k,ans);
        return ans;
    }





int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        int sum=0;
        int left=0;
        int right=0;
        while(right<nums.size()){
            while(mp.find(nums[right])!=mp.end()){
                mp.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            mp[nums[right]]=right;
            sum+=nums[right];
            ans=max(ans,sum);
            right++;
        }
        return ans;
    }





// find maximum subarray of sum totalSum-x 
    int minOperations(vector<int>& nums, int x) {
        map<int,int> mp;// prefix sum and index
        mp[0]=-1;
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int target=totalSum-x;
        int maxLen=-1;
        int prefix=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            mp[prefix]=i;
            if(mp.find(prefix-target)==mp.end()){
            }
            else{
                maxLen=max(maxLen,i-mp[prefix-target]);
            }
        }
        if(maxLen==-1) return -1;
        return nums.size()-maxLen;
    }




// two approaches
    // first is to use two stacks or stack of pairs
    // where for each element we can store minimum till then
    
    // other one in one we can can calculate min with the help of prev element
    stack<int> st;
    int mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val>=mini) st.push(val);
            else{
                st.push(2*val-mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        int curr=st.top();
        st.pop();
        if(curr<=mini){
            mini=2*mini-curr;
        }
    }
    
    int top() {
        int curr=st.top();
        if(curr<mini) return mini;
        else return curr;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }





class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
     
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        //next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1) {
            return false;
        }
        
        //find index
        int index = freespot;
        
        //insert element into array
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
       
        //update next;
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index= top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};






