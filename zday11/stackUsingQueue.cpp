// stack using queue
// we can do this using 2 queue and 1 queue
// if we use 2 queue we can do it in two ways
// making push(optimal) costlier or making pop costlier
// making push costlier
// take two queue , q1 and q2 , push in q2 then push all element of q1 in q2 then swap 
// pop and top is simple
// OR we can do this with only one queue as well
// push in queue and for size -1 elements push the front again and pop
class MyStack {
public:
    // queue<int> q1;
    // queue<int> q2;
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // swap(q1,q2);
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // int ans=q1.front();
        // q1.pop();
        // return ans;
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        // return q1.front();
        return q.front();
    }
    
    bool empty() {
        // return q1.empty();
        return q.empty();
    }
};

