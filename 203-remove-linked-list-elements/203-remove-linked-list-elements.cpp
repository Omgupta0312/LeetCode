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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr=head,*prev=NULL;
        while(curr!=NULL && curr->val==val)
        {
            ListNode*t=curr;
            curr=curr->next;
            delete t;
        }
        head=curr;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                ListNode*t=curr;
                curr=curr->next;
                prev->next=curr;
                delete t;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};