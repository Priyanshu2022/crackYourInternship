// merge k sorted lists
// compare class in priority queue
// put all first element of lists in min heap
// take and attach , push next of that
class cmp{
        public:
        bool operator()(const ListNode* a,const ListNode* b){
            return( a->val>b->val);
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lists.size();i++) if(lists[i]!=NULL) pq.push(lists[i]);
        while(!pq.empty()){
            ListNode* least=pq.top();
            pq.pop();
            temp->next=least;
            temp=temp->next;
            if(least->next) pq.push(least->next);
        }
        return dummy->next;
    }
};