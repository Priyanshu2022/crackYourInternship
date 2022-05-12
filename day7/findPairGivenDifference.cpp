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