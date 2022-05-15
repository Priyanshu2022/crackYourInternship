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



