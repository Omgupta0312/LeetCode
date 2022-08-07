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
    ListNode* swapPairs(ListNode* head) {
        ListNode *t=head,*p=NULL;
        while(t!=NULL && t->next!=NULL)
        {
            ListNode*a=t,*b=t->next;
            a->next = b->next;
            b->next = a;
           
            t=a->next;
            if(p==NULL){ 
                head=b;
                p=a;
                p->next=t;
            }
            else{
                p->next=b;
                p=p->next->next;
            }
            
        }
        return head;
    }
};