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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        
        int k=n;
        int c=0;
        ListNode*s,*f,*h;
        s=NULL;
        f=head;
        while(f!=NULL)
        {
            if(s!=NULL)
            {
                 s=s->next;
            }
            
           
            if(k==0)
            {
                s=head;
                h=s;
            }
            k--;
            
            f=f->next;
            c++;
          
        }
        if(s!=NULL)
           s->next=s->next->next;
        
        
        else if(s==head)
        {
            s=s->next;
            head=s;
        }
        
        else if(c-n==0)
        {
           head=head->next;
        }
        
        
        
        return head;
    }
};