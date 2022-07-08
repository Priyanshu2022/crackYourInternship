// find median from data stream
// manitain a min heap and a max heap
// top of maxheap is greater than number push in maxheap
// else in minheap
// if differnce of size is more than one , transfer one element from one to another
// Now to get median -> if size are equal , add the top and divide by 2
// else return the top of greater size
priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top()>=num){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()) return (maxheap.top()+minheap.top())/2.0;
        return maxheap.size()>minheap.size()?maxheap.top():minheap.top();
    }