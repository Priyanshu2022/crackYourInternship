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