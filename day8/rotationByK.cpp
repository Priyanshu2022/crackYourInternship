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