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