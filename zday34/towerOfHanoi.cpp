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