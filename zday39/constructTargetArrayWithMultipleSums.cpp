// construct target array with multiple sums
// convert array to 1 1 1 . . 
using ll=long long ;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        ll sum=0;
        priority_queue<ll> pq;
        for(auto it:target) pq.push(it),sum+=it;
        while(!pq.empty()){
            ll maxi=pq.top();
            pq.pop();
            ll remaining_sum=sum-maxi;
            if(maxi==1 || remaining_sum==1) return true;
            if(remaining_sum==0 || maxi<remaining_sum) return false;
            ll new_val=maxi%remaining_sum;
            if(new_val==0) return false;
            pq.push(new_val);
            sum=remaining_sum+new_val;
        }
        return true;
    }
};