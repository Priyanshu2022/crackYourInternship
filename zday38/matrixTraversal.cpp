ll n;
    cin>>n;
    ll a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    vector<vector<ll>> v(2*n-1);

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            v[i+j].push_back(a[i][j]);
        }
    }

    for(auto it:v){
        for(auto cur:it) cout<<cur<<" ";
        cout<<endl;
    }