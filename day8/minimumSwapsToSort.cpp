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