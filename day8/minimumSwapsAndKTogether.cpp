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