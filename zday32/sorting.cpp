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