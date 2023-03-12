/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:lists)
        {
            ListNode *head=x;
            while(head!=NULL)
            {
                pq.push(head->val);
                head=head->next;
            }
        }
        ListNode*head=NULL,*tail=NULL;
        
        while(pq.empty()==false)
        {
            int x=pq.top();
            pq.pop();
            ListNode *temp=new ListNode(x);
            if(head==NULL)
            {
                head=temp;
                tail=head;
            }
            
            else{
                tail->next=temp;
                tail=tail->next;
            }
        }
        
        return head;
    }
};