/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *curr=node,*prev=node;
        while(curr!=NULL)
        {
            curr->val = curr->next->val;
            prev=curr;
            curr=curr->next;
            
            if(curr->next==NULL)
            {
                prev->next=NULL;
                delete curr;
                break;
            }
        }
    }
};